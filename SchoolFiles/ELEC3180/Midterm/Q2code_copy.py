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


def getRecBipart(cov, sortIx):
    # Compute HRP alloc
    w = pd.Series(1, index=sortIx)
    cItems = [sortIx]  # initialize all items in one cluster
    while len(cItems) > 0:
        cItems = [i[j:k] for i in cItems for j, k in ((0, len(i) // 2), (len(i) // 2, len(i))) if len(i) > 1]  # bi-section
        for i in range(0, len(cItems), 2):  # parse in pairs
            cItems0 = cItems[i]  # cluster 1
            cItems1 = cItems[i + 1]  # cluster 2
            cVar0 = getClusterVar(cov, cItems0)
            cVar1 = getClusterVar(cov, cItems1)
            alpha = 1 - cVar0 / (cVar0 + cVar1)
            w[cItems0] *= alpha  # weight 1
            w[cItems1] *= 1 - alpha  # weight 2
    return w



def getIVP(cov, **kargs):
    # Compute the inverse-variance portfolio
    ivp = 1. / np.diag(cov)
    ivp /= ivp.sum()
    return ivp


def getClusterVar(cov,cItems):
    # Compute variance per cluster
    cov_=cov.loc[cItems,cItems] # matrix slice
    w_=getIVP(cov_).reshape(-1,1)
    cVar=np.dot(np.dot(w_.T,cov_),w_)[0,0]
    return cVar

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
    # log_returns_1 = dataset_log_returns.loc['2015-01-06':'2015-05-29']
    log_returns_1 = dataset_log_returns
    stock_namelist = ['IDXX', 'IQV', 'DTE', 'VZ', 'UAL']
    log_returns_1 = dataset_log_returns.loc[:,stock_namelist]
    Sigma = np.cov(log_returns_1.T)

    # Fill in the right argument to get the plots and new order of stocks:
    sortIx = hrp_s12(Sigma, stock_namelist, ifplot= True)
    # After finish the function of stage 3, call it and print the final weight:
    w_hrp = hrp_s3(Sigma, stock_namelist, sortIx)
    print(w_hrp)