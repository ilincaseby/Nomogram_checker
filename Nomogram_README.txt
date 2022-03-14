I created functions that read the matrixes, one for the main matrix that represents the matrix created to be verified
while two more read the matrixes used for restrictions (one for lines one for columns).
The functions that verify the lines works like that:
Go for every line in every column, when I meet a 1 I start counting, after I see a 0 I compare the dimension of the group
with the restriction and so on, that's the principle used for columns too, but reversed, if it's all ok I return 1.
These two functions return 1 if the restrictions are followed and I declare in a main two variables, if both are 1 means that
the game is done correctly, otherwise it's not.