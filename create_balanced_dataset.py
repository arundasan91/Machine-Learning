import numpy as np
import random

def make_balanced(X,Y):
    "Binary label balancer function used for stutter-fluent binary classifier"
    try:
        # more fluent than stutter trials. choose randomly as much stutter trials from the fluent and concat.
        # np.where(Y_array==0) will give the indices where the array is 0 (fluent).
        # then using np.random.choice, we choose X_array[Y_array==1].shape[0] (stutter) number of samples from the fluent trials.
        # later we concatenate both data points to create a balanced dataset.
        random_data_points = np.random.choice(np.where(Y==0)[0], size=X[Y==1].shape[0], replace=False)
        assert random_data_points.shape[0] == X[Y==1].shape[0]
        random_data_points = np.concatenate((random_data_points, np.where(Y==1)[0]))
        random.shuffle(random_data_points)

    except ValueError:
        # more stutter than fluent trials. choose randomly as much fluent trials from the stutter and concat.
        random_data_points = np.random.choice(np.where(Y==1)[0], size=X[Y==0].shape[0], replace=False)
        assert random_data_points.shape[0] == X[Y==0].shape[0]
        random_data_points = np.concatenate((random_data_points, np.where(Y==0)[0]))
        random.shuffle(random_data_points)
    return(X[random_data_points], Y[random_data_points])
