# Smart-elephant

Analyze a collection of elephants and place as large a subset of elephants as possible into a sequence whose weights are increasing but IQ's are decreasing.


***Input***

-The data for each elephant will consist of a pair of integers : the first -> its size in kilograms and second-> its IQ.

-Both integers are between 1 - 10000

-The data contains information on at most 1000 elephants.

-Two elephants may have the same weight with different IQs, or the same weight with the same IQ.


***OUTPUT***

-The first output line contain an integer n, the length of elephant sequence found.

-The second line should contain positive integers representing the elephant indices in order of the sequence.

-The elephant index starts from 1.

-If multiple sequences are found, output the sequence having the smallest sum of weights and IQs in the sequence.

-If the length of the sequence is less than two, output the elephant index having the smallest sum of weights and IQs.
