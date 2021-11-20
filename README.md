# Finding similarity in data points using KD tree

In this project, we implemented the nearest neigbours algorithm using KD Tree data structure so as to predict the outcome of a given set of data points by figuring out its similarity between other existing data points in the database.


To run the program,
compile and execute main.c file.

# Input

The input is in a text format.

1st line : k (how many dimensions)

2nd line : How many data points to be input

3rd line : How many nearest neighbour to find


Then the data points are input line by line

The last line contains the data set for which nearest neighbors are to be found


For the given input file,

The dataset represents the following : 

1st column : Age of consumer                 (1st dimension)

2nd column : Estimated Salary of Consumer    (2nd dimension)

3rd column (target column) : Whether he/she buys the given product or not (outcome)


# Output

The program will give us the number of nearest neighbours for the given data point.

Nearest neighbour here means the the new data point for which the outcome is to be predicted will behave similarily to how its majority of neighbourhood behaves 


For eg : 

We have asked for 6 nearest neighbors for this new point

Given Test Case : 36 33000                      Original Outcome : 0


Output : Our program will output 6 nearest neighbours for the give point :

35 38000 

37 33000 

41 30000 

35 25000 

39 42000 

35 27000


If we see our given data set, the outcome corresponding to these datapoints are 

35 38000 0

37 33000 0

41 30000 0

35 25000 0

39 42000 0

35 27000 0


So, we can see majority of the data points (all in this case) are giving 0 as outcome i.e. he/she will not buy the particular product.

So, predicted outcome : 0 which is same as the expected outcome.


We also checked like this for other random data points and got an accuracy of  .




