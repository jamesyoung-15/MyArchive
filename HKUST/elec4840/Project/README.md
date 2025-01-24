# ELEC4840 Final Project By Young, James Yang (20740589)

For this project, I chose to use Pseudo-labeling (Semi-Supervised Learning) and FACT framework (Domain Generalization) for improving Skin Lesion Classification in the ISIC 2016 Challenge Dataset.

Report in [here](./ELEC4840_Project_Report.pdf). Presentation in [here](./ELEC4840-Project-Presentation.pdf).

## Key Results

| Method                                      | AUC    | Accuracy    |
|---------------------------------------------|--------|-------------|
| Supervised Only (Baseline)                  | 77.7%  |  79.4%      |
| Semi-Supervised Learning (Pseudo-Labeling)  | 81.4%  |  82.1%      |
| Domain Generalization     (FACT)            | 71.5%  |  80.4%      |

## Details

See [report]() for details.

## Project

### Prerequites

Uses 2016 ISIC skin lesion data for labelled data (900 training images, 329 testing images) and for unlabeled data uses 2017 ISIC skin lesion data (2000 images). The data is found [here](https://challenge.isic-archive.com/data/). Can be installed using below:

``` bash
wget https://isic-challenge-data.s3.amazonaws.com/2016/ISBI2016_ISIC_Part3_Training_Data.zip && wget https://isic-challenge-data.s3.amazonaws.com/2016/ISBI2016_ISIC_Part3_Test_Data.zip && wget https://isic-challenge-data.s3.amazonaws.com/2016/ISBI2016_ISIC_Part3_Training_GroundTruth.csv && wget https://isic-challenge-data.s3.amazonaws.com/2016/ISBI2016_ISIC_Part3_Test_GroundTruth.csv && unzip "./ISBI2016_ISIC_Part3_Test_Data.zip" && unzip "./ISBI2016_ISIC_Part3_Training_Data.zip" && wget https://isic-challenge-data.s3.amazonaws.com/2017/ISIC-2017_Training_Data.zip && unzip "./ISIC-2017_Training_Data.zip"
```

Required libraries are in `requirements.txt`, can use `pip install -r requirements.txt`.

### Code

The codes are in the Juypter notebooks:

`Skin-Lesion-Baseline.ipynb` contains the baseline result using supervised learning only.

`Skin-Lesion-SSL.ipynb` contains the semi-supervised learning method using pseudo labeling.

`Skin-Lesion-FACT.ipynb` contains the domain generalization method using Fourier Augmented Co-Teacher (FACT) framework.
