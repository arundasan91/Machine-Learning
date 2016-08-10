##A C++ Project to find the best features to train the algorithm on.

##Abstract
High quality Datasets are of prime importance for Machine Learning. So is choosing the best features from the dataset to train the program. The Project focuses on the selection of features from these huge dataset files according to its Entropy and Information Gain parameters. Entropy is the measure of impurity in the dataset and Information Gain is the parameter which decides which feature to choose. This problem is particular to Decision Tree algorithms. The more the Information Gain, the better. The Project will give user the ability to read a binary classified dataset. It will find the Entropy and Information Gain of various features and will select the best features among them so as to yield the best result out of our Decision Tree.

##Background
-	Machine learning is a type of artificial intelligence (AI) that provides computers with the ability to learn without being explicitly programmed. Machine learning focuses on the development of computer programs that can teach themselves to grow and change when exposed to new data.
-	Various machine learning applications are usually overwhelmed with a large number of features. The task of feature selection in these applications is to improve a performance criterion such as accuracy, but often also to minimize the cost associated in producing the features.
-	Feature selection reduces the dimensionality of feature space, removes redundant, irrelevant, or noisy data. It brings the immediate effects for application: speeding up a data mining algorithm, improving the data quality and thereof the performance of data mining.
-	Information Gain (IG) is an entropy-based feature evaluation method, widely used in the field of machine learning. It is defined as the amount of information provided by the feature for the Machine Learning algorithm

##Results 
###Pseudocode
1.	Set the filename.
2.	Load the dataset and save it to a vector of vectors.
3.	Find the number of features, maximum number of attributes in each features.
4.	Find the probability of each attributes in each of the features.
5.	Find the entropy of each of the features
6.	Find the information gain that can be achieved using each of the features.
7.	Choose the best features that will provide the highest accuracy.
8.	Write the features into a new dataset file and store it locally.

###Dataset Used
In 1991 Sebastian Thrun composed these datasets for benchmarking many known learning algorithms. These datasets were generated using propositional formulas over six attributes. In addition to this, the third dataset was added with 5% classification noise. All the three data sets have an XOR flavor by design. Using a naive Bayesian classifier with AdaBoost algorithm, Elkan reports that the classifier succeeded only on the third dataset. With the addition of noise this situation changes and the boosting algorithm takes advantage of it to produce better classification.
All 3 of the Monk’s datasets are provided with the project.

###Obtained Results (Showing only for Monk 2 datset)

Table 1. Information Gain achieved for different features.

| Feature | Information Gain  |
|:-------:|:-----------------:|
| 1       | 0.370476          |
| 2       | 0.370476          |
| 3       | 0.00222753        |
| 4       | 0.370476          |
| 5       | 0.501114          |
| 6       | 0.00222753        |  

Table 2. Best features extracted from the dataset and their information gain.

| Feature | Information Gain  |
|:-------:|:-----------------:|
| 1	      | 0.370476          |
| 2	      | 0.370476          |
| 4	      | 0.370476          |
| 5	      | 0.501114          |

##Issues and Conclusion
A simple averaging feature extraction algorithm based on information gain is implemented. The same code can be adapted to other algorithms to make complex decisions for extracting the features. The program is written with speed and efficiency in mind. The usage of vectors instead of arrays and proper deletion of dynamically allocated memory is a few points highlighting it.

Dataset handling and feature extraction are handled separately as different Classes to promote easy maintenance and scaling. This also makes the code neat and tidy. For anyone going through the code, a printVector function is provided which when uncommented will be able to print vectors of any dimension and any type. The printVector function is overloaded to work with any type of data.

There is no requirement to mention the number of features in the dataset or the number of attributes the features have. Every aspect is taken care by the program. The only input from the user is the filename of the dataset.

The downside of the project is that the dataset should be preprocessed before sending in to the program. The program assumes that the data is categorized and that the labels are saved in the last column. The features can be saved in any column other than the last. This is required to assure that proper parent feature is selected for the information gain calculation.

Another issue is that the program is written to work on datasets with a maximum of 6 different attributes for any feature. Attributes are the different kind of values that are present in each of the feature’s (columns). This can be scaled very easily to any number of attributes but to demonstrate the project the number is chosen less. It should be noted that if the program works for 6 different attributes, it will work for any number of attributes since the algorithm and basic logic applied is the same. It is only a matter of scaling the code to occupy more attributes.

##Reference
1.	Monk’s Problems available at: https://archive.ics.uci.edu/ml/machine-learning-databases/monks-problems/monks.names
2.	Monk 2 Dataset available at: http://sci2s.ugr.es/keel/dataset.php?cod=65
3.	C++ vector memory and 2D vectors available at: http://www-h.eng.cam.ac.uk/help/tpl/languages/C++/vectormemory.html
4.	Efficient vector of vectors available at: http://upcoder.com/2/efficient-vectors-of-vectors
5.	Convert string to float. More info available at: http://www.cplusplus.com/reference/string/stof/




