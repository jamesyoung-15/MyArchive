import numpy as np
import math
import cvxpy as cp
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import scipy.cluster.hierarchy as sch,random
import warnings
warnings.filterwarnings('ignore')
plt.style.use('ggplot')
dataset_log_returns = pd.read_csv('dataset.csv', index_col=0, parse_dates=True)

# Part B:

# The function you need to write.
# Input: cov: a dataframe containing the covariance matrix of stocks.
#        sortIx: a list containing the stocks names, ordered by the stage 1&2.
#        You can add any input argument if you need.
# Output: allocation weight. You can output any data type as long as you can use it properly in Q3.
def getRecBipart(cov,sortIx):
    # weights
    w_n = np.ones(len(sortIx))

    # # list of stocks sorted by index number from sortIx strings
    # L = [log_returns_1.columns.get_loc(i) for i in sortIx]

    # bisect manually

    # bisect sortIx into L1 and L2
    l1, l2 = bisect(sortIx)
    weightAllocationIndex(l1,l2,Sigma, w_n)
    # Bisect L1 into subsets:

    # split into subsets l1_bis1 = {1,2} l1_bis2 = {3,4,5}
    l1_bis1, l1_bis2 = bisect(l1)
    weightAllocationIndex(l1_bis1,l1_bis2,Sigma, w_n)


    # l1_bis3 = {1} l1_bis4 = {2}
    l1_bis3, l1_bis4 = bisect(l1_bis1)
    weightAllocationIndex(l1_bis3,l1_bis4,Sigma, w_n)

    #l1_bis5 = {3} l1_bis6 = {4,5}
    l1_bis5, l1_bis6 = bisect(l1_bis2)
    weightAllocationIndex(l1_bis5,l1_bis6,Sigma, w_n)

    # l1_bis7 = {3} l1_bis8 = {4}
    l1_bis7, l1_bis8 = bisect(l1_bis6)
    weightAllocationIndex(l1_bis7,l1_bis8,Sigma, w_n)

    # Bisect L2 into subsets, same as above but for L2

    # split into subsets l2_bis1 = {1,2} l1_bis2 = {3,4,5}
    l2_bis1, l2_bis2 = bisect(l2)
    weightAllocationIndex(l2_bis1,l2_bis2,Sigma, w_n)


    # l1_bis3 = {1} l1_bis4 = {2}
    l2_bis3, l2_bis4 = bisect(l2_bis1)
    weightAllocationIndex(l2_bis3,l2_bis4,Sigma, w_n)

    #l1_bis5 = {3} l1_bis6 = {4,5}
    l2_bis5, l2_bis6 = bisect(l2_bis2)
    weightAllocationIndex(l2_bis5,l2_bis6,Sigma, w_n)

    # l1_bis7 = {3} l1_bis8 = {4}
    l2_bis7, l2_bis8 = bisect(l2_bis6)
    weightAllocationIndex(l2_bis7,l2_bis8,Sigma, w_n)
    
    # !use stock_namelist for index otherwise out of order
    w_n = pd.DataFrame(w_n, index = stock_namelist, columns =['Weights'])
    return w_n





# Helper functions for Question 2

# 2.1 helper: 
## someArray is bisected and returns tuple of bisected arrays
def bisect(someArray):
    bisect1 = someArray[:len(someArray)//2]
    bisect2 = someArray[len(someArray)//2:]
    return bisect1, bisect2

# 2.2, 2.3, 2.4 helper:
## arr1 is either L1, arr2 is L2, cov is Sigma, w_n is the weights to be updated based on calculations
def weightAllocationIndex(arr1, arr2, cov, w_n):
    # just in case initialization
    stock_namelist = dataset_log_returns.columns.values.tolist()
    log_returns_1 = dataset_log_returns.loc['2015-01-06':'2015-05-29']
    Sigma = np.cov(log_returns_1.T)
    cov = pd.DataFrame(Sigma, columns = stock_namelist, index = stock_namelist)
    
    # get the log returns from the specified stocks in arr1 and arr2 
    log_ret_1 = log_returns_1.loc[:,arr1]
    log_ret_2 = log_returns_1.loc[:,arr2]

    # 2.2: Calculation for tilde Vi by finding Li, tilde wi, vi 
    # calculate v1, v2
    arr1_cov = cov.loc[arr1, arr1]
    arr2_cov = cov.loc[arr2, arr2]
    # calculate tilde w1 and w2 based on formula given
    w1 = np.diag(arr1_cov)**-1 / np.trace(np.diag(np.diag(arr1_cov)**-1))
    w2 = np.diag(arr2_cov)**-1 / np.trace(np.diag(np.diag(arr2_cov)**-1))
    # convert them to 2d array
    w1 = w1.reshape(-1,1)
    w2 = w2.reshape(-1,1)
    #calculate tilde v1, v2 from formula
    v1 = np.dot(np.dot(w1.T,arr1_cov),w1)
    v2 = np.dot(np.dot(w2.T,arr2_cov),w2)
    
    # 2.3: Compute split factor
    alpha = 1- (v1/(v1+v2))
    arr1_indices = [log_returns_1.columns.get_loc(i) for i in arr1]
    arr2_indices = [log_returns_1.columns.get_loc(i) for i in arr2]
    
    # 2.4: rescale allocations depending on if l1 or l2
    for i in arr1_indices:
        w_n[i] *= alpha
    for j in arr2_indices:
        w_n[j] *= (1-alpha)



# A sub function for the satge 1 and 2, called in the hrp_s12()
def getQuasiDiag(link):
    link=link.astype(int)
    sortIx=pd.Series([link[-1,0],link[-1,1]])
    numItems=link[-1,3]
    while sortIx.max()>=numItems:
        sortIx.index=range(0,sortIx.shape[0]*2,2)
        df0=sortIx[sortIx>=numItems]
        i=df0.index;j=df0.values-numItems
        sortIx[i]=link[j,0]
        df0=pd.Series(link[j,1],index=i+1)
        sortIx=sortIx.append(df0)
        sortIx=sortIx.sort_index()
        sortIx.index=range(sortIx.shape[0])
    return sortIx.tolist()

# Transform the correlation matrix to a distance matrix
def correlDist(corr, n_stock):
    dist=((1-corr)/2.)**.5
    for i in range(n_stock):
        dist.iloc[i,i] = 0
    return dist

# Plot the heatmap of the correlation matrix
def plotCorrMatrix(path,corr,labels=None):
 #
    if labels is None:labels=[]
    plt.pcolor(corr)
    plt.colorbar()
    plt.yticks(np.arange(.5,corr.shape[0]+.5),labels)
    plt.xticks(np.arange(.5,corr.shape[0]+.5),labels)
    plt.savefig(path)
    plt.clf();plt.close()
    return

# Function for Stage 1 and 2
def hrp_s12(cov,stock_namelist, ifplot = False):
    n_stock = len(stock_namelist)
 #1) compute and plot correlation matrix
    v = np.diag(np.sqrt(1/np.diag(cov)))
    corr = np.dot(np.dot(v,cov), v)
    cov = pd.DataFrame(cov, columns = stock_namelist, index = stock_namelist)
    corr = pd.DataFrame(corr, columns = stock_namelist, index = stock_namelist)
    if (ifplot): plotCorrMatrix('HRP_corr0.png',corr,labels=corr.columns)
 #2) cluster
    dist=correlDist(corr,n_stock)
    link=sch.linkage(dist,'single')

    sortIx=getQuasiDiag(link)
    sortIx=corr.index[sortIx].tolist() # recover labels
    df0=corr.loc[sortIx,sortIx] # reorder
    if (ifplot): plotCorrMatrix('HRP_corr1.png',df0,labels=df0.columns)
    return sortIx

def hrp_s3(cov,stock_namelist,sortIx):
    cov = pd.DataFrame(cov, columns = stock_namelist, index = stock_namelist)
    # Finish this function getRecBipart(cov,sortIx).
    hrp = getRecBipart(cov,sortIx)
    # Please print and check the "hrp" returned by the "getRecBipart(cov,sortIx)".
    # The order of stocks in "hrp" maybe follow the "sortIx", which is different from the "stock_namelist".
    # I suggest you to restore the order of "hrp" to "stock_namelist" here,
    # in order to avoid mistakes in Q3.
    # My "hrp" is a pandas.series, so this is what I do:
    # hrp = hrp[stock_namelist]
    # It's OK if you want to finish this step in "getRecBipart()".
    # It's also Ok if you want to skip this step here and deal with this small order problem in Q3.
    return hrp

if __name__ == '__main__':
    stock_namelist = dataset_log_returns.columns.values.tolist()
    log_returns_1 = dataset_log_returns.loc['2015-01-06':'2015-05-29']
    Sigma = np.cov(log_returns_1.T)

    # Fill in the right argument to get the plots and new order of stocks:
    sortIx = hrp_s12(Sigma, stock_namelist, ifplot= True)
    # After finish the function of stage 3, call it and print the final weight:
    w_hrp = hrp_s3(Sigma, stock_namelist, sortIx)
    print(w_hrp)