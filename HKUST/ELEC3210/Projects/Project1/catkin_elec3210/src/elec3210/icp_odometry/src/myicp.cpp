#include "myicp.h"



// :sourcePointCloud(new pcl::PointCloud<pcl::PointXYZ>), targetPointCloud(new pcl::PointCloud<pcl::PointXYZ>),transformedSourcePointCloud(new pcl::PointCloud<pcl::PointXYZ>)
MY_ICP::MY_ICP(int maxIterations, double maxDistance, double transformationEpsilon){
    this->maxIterations = maxIterations;
    this->maxDistance = maxDistance;
    this->transformationEpsilon = transformationEpsilon;
    sourcePointCloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
    targetPointCloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
}

void MY_ICP::setInputSource(pcl::PointCloud<pcl::PointXYZ>::Ptr sourcePointCloud){
    this->sourcePointCloud = sourcePointCloud;
}

void MY_ICP::setInputTarget(pcl::PointCloud<pcl::PointXYZ>::Ptr targetPointCloud){
    this->targetPointCloud = targetPointCloud;
}

void MY_ICP::setInitialGuess(Eigen::Matrix4d init_guess){
    this->finalTransformation = init_guess;
}

/* Refer to Lecture 5 ICP */
void MY_ICP::computeICP(){
    // create new point cloud variable to store transformation applied to source
    pcl::PointCloud<pcl::PointXYZ>::Ptr copySourcePointCloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::copyPointCloud(*sourcePointCloud, *copySourcePointCloud);
    
    // apply initial guess
    pcl::transformPointCloud(*sourcePointCloud, *copySourcePointCloud, finalTransformation);

    // setup kdtree for finding nearest neighbor, code resource: https://pcl.readthedocs.io/projects/tutorials/en/latest/kdtree_search.html
    pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;
    kdtree.setInputCloud(targetPointCloud);
    int K = 1;
    std::vector<int> pointIdxKNNSearch(K);
    std::vector<float> pointKNNSquaredDistance(K);
    // other init variables
    Eigen::Matrix4d transformationIteration;
    double previousError = 0;
    double meanError = 0;

    for(int i=0;i<maxIterations;i++){
        pcl::transformPointCloud(*sourcePointCloud, *copySourcePointCloud, finalTransformation);
        /* find nearest neighbor based on current rotation and translation */
        // update correspondence
        correspondencePoints.clear();
        for(const auto& sourcePoint: copySourcePointCloud->points){
            // code resource: https://pcl.readthedocs.io/projects/tutorials/en/latest/kdtree_search.html
            // perform nearest neighbor search
            kdtree.nearestKSearch (sourcePoint, K, pointIdxKNNSearch, pointKNNSquaredDistance);
            /// get and store neighbor point
            pcl::PointXYZ resultPoint = (*targetPointCloud)[pointIdxKNNSearch[0]];
            // create correspondence point, update correspondence points vector
            correspondencePoint singleCorrespondence(sourcePoint, resultPoint);
            neighborInfo.distances.push_back(pointKNNSquaredDistance[0]);
            correspondencePoints.push_back(singleCorrespondence);
        }

        // get updated transformation matrix
        transformationIteration = computeTransformationMatrix();

        /* calculate mean error */
        // error calculation source: https://github.com/zjudmd1015/icp/blob/master/icp.cpp
        meanError = std::accumulate(neighborInfo.distances.begin(),neighborInfo.distances.end(),0.0)/neighborInfo.distances.size();
        if(abs(previousError-meanError)<transformationEpsilon)
            break;
        previousError = meanError;

        // update transformation
        finalTransformation = transformationIteration * finalTransformation;
        // pcl::transformPointCloud(*sourcePointCloud, *copySourcePointCloud, finalTransformation);
        
    }


}
/*
* Steps:
* 1. calculate SVD
*      i. compute mean
*      ii. compute mean-reduced coordinate
*      iii. get covariance matrix
* 2. calculate rotation matrix
* 3. calculate translation matrix
* 4. combine to create transformation matrix
*/
Eigen::Matrix4d MY_ICP::computeTransformationMatrix(){

    /* Compute means of the point clouds */
    // init variables
    float pointCloudSize = correspondencePoints.size();
    // useful resource: https://eigen.tuxfamily.org/dox/group__TutorialAdvancedInitialization.html
    Eigen::Vector3f sourceMean = Eigen::Vector3f::Zero();
    Eigen::Vector3f targetMean = Eigen::Vector3f::Zero();

    // get x y z sum for each point cloud
    for(const auto& correspondence: correspondencePoints){
        sourceMean += Eigen::Vector3f(correspondence.sourcePoint.x, correspondence.sourcePoint.y,correspondence.sourcePoint.z);
        targetMean += Eigen::Vector3f(correspondence.targetPoint.x, correspondence.targetPoint.y,correspondence.targetPoint.z);
    }
    // safe check
    if(pointCloudSize!=0){
        // divide sum by total size for mean
        sourceMean /= pointCloudSize;
        targetMean /= pointCloudSize;
    }

    /* Compute mean-reduced coordinate and covariance matrix */
    // covariance matrix, sum of a*b^t*p_n, where a and b are mean-reduced coordinates, equation from lecture notes
    Eigen::Matrix3d H = Eigen::Matrix3d::Zero(3,3); //seems to need to initialize to 0 had some inconsistent results without it
    for(const auto& correspondence: correspondencePoints){
        // L5 page 23: H = sum(an*bn^t), an = (xn-x0), bn = (yn-y0)
        H(0,0) += (correspondence.sourcePoint.x - sourceMean(0)) * (correspondence.targetPoint.x - targetMean(0));
        H(0,1) += (correspondence.sourcePoint.x - sourceMean(0)) * (correspondence.targetPoint.y - targetMean(1));
        H(0,2) += (correspondence.sourcePoint.x - sourceMean(0)) * (correspondence.targetPoint.z - targetMean(2));
        H(1,0) += (correspondence.sourcePoint.y - sourceMean(1)) * (correspondence.targetPoint.x - targetMean(0));
        H(1,1) += (correspondence.sourcePoint.y - sourceMean(1)) * (correspondence.targetPoint.y - targetMean(1));
        H(1,2) += (correspondence.sourcePoint.y - sourceMean(1)) * (correspondence.targetPoint.z - targetMean(2));
        H(2,0) += (correspondence.sourcePoint.z - sourceMean(2)) * (correspondence.targetPoint.x - targetMean(0));
        H(2,1) += (correspondence.sourcePoint.z - sourceMean(2)) * (correspondence.targetPoint.y - targetMean(1));
        H(2,2) += (correspondence.sourcePoint.z - sourceMean(2)) * (correspondence.targetPoint.z - targetMean(2));
    }

    // debug
    // std::cout<< "Point cloud size (source,target, loopcount): "<< sourcePointCloud->points.size() <<" " << targetPointCloud->points.size() << " " << pointCloudSize <<std::endl;
    // std::cout<< "Source mean: x=" << sourceMean(0) << " y="<< sourceMean(1) << " z=" << sourceMean(2) << std::endl; 
    // std::cout<< "Target mean: x=" << targetMean(0) << " y="<< targetMean(1) << " z=" << targetMean(2) << std::endl; 
    // std::cout<<"Covariance Matrix: \n" << H << std::endl;


    /*  compute svd, reference: https://eigen.tuxfamily.org/dox/classEigen_1_1JacobiSVD.html */
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(H, Eigen::ComputeFullU | Eigen::ComputeFullV);
    Eigen::Matrix3d U = svd.matrixU();
    Eigen::Matrix3d V = svd.matrixV();

    // compute rotation matrix
    Eigen::Matrix3d rotationMatrix = V * U.transpose();
    // verify whether its determinant is greater than 0 to ensure that it complies with the right-hand coordinate system
    if (rotationMatrix.determinant() < 0)
    {
        U.col(2) *= -1;
        rotationMatrix = V * U.transpose();
    }

    // compute translation vector, equation from lecture notes
    Eigen::Vector3d translationVector = Eigen::Vector3d(targetMean(0), targetMean(1), targetMean(2)) - rotationMatrix * Eigen::Vector3d(sourceMean(0), sourceMean(1), sourceMean(2));

    // combine rotation and translation to create 4x4 transformation matrix
    Eigen::Matrix4d transformationMatrix = Eigen::MatrixXd::Identity(4,4);
    transformationMatrix.block<3, 3>(0, 0) = rotationMatrix;
    transformationMatrix.block<3, 1>(0, 3) = translationVector;
    
    return transformationMatrix;

}
