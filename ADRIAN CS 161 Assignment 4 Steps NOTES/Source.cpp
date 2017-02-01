#include <iostream>
#include <string>
#include <sstream>
#include <istream>

using namespace std;

/*
Feedback

Score

10 / 10 - 100 %
Feedback Date

May 22, 2016 4:07 PM
Dropbox Feedback

Looks good and you get full credit for it.I would like to point out that there are a couple areas you could improve this.First of all, you could use a function for the input.I think that you figured this out in later lessons.

The second this is to avoid using "break" (unless in a switch statement).Using break to get out of loops is a bad habit to get into.It is much better, and cleaner, programming practice to restructure your loops to avoid break.In your case you could have had your while loop say :

while (i < Int2 && Step > 0 && Total <= Int2)

Finally, it is better to use more descriptive variable names.

*/


int main()

{
	//declare variables
	int Int1;
	int Int2;
	int Int3;
	int e = 1;
	int i = 0;
	int InputLength;
	bool GetInput;
	string Input;
	char c;
	string CleanInput;

	stringstream ss;
	string mtype;

	while (e < 4)
	{
		GetInput = true;

		while ((GetInput == true))
		{
			if (e == 1)
			{
				mtype = "Beginning";
			}
			else if (e == 2)
			{
				mtype = "Ending";
			}
			else
			{
				mtype = "Increment";
			}

			cout << "Enter " + mtype + " Integer: ";
			getline(cin, Input);
			InputLength = (Input.length());

			//After making sure the user entered something, loop through each character in their input, checking to see if it is a digit.
			//

			if (InputLength > 0)
			{

				while ((i < (InputLength)))
				{
					c = Input.at(i);

					if (isdigit(c))
					{
						CleanInput = CleanInput + c;
						++i;
					}
					else
					{
						i = 0;
						cout << "Invalid input for " + mtype + " integer, at digit check." << '\n';
						break;
					}
				}

				//Since we break out of the digit checking loop when we encounter an invalid character, we need a conditional to check if we went through the whole string or not.
				//

				if ((i == InputLength))
				{

					//The user's input is valid, check to see which variable we store it in and do so, reset variables, then go to the next question.
					//

					ss << CleanInput;

					if (e == 1)
					{
						ss >> Int1;
					}
					else if (e == 2)
					{

						//Note that you actually need another loop here. Int2 is our ending value, so you have to make sure its bigger than your starting value.
						//
						ss >> Int2;
					}
					else
					{
						ss >> Int3;
					}

					i = 0;
					cin.clear();
					ss.clear();
					ss.str("");
					Input = "";
					CleanInput = "";
					InputLength = 0;
					e++;
					GetInput = false;
				}
				else
				{
					i = 0;
					cin.clear();
					ss.clear();
					ss.str("");
					Input = "";
					CleanInput = "";
					InputLength = 0;

					//The message below is just for debugging purposes.  Delete it after the code is working fine.
					//
					cout << "Invalid input for " + mtype + " integer, at length check." << '\n';
					break;
				}

			}
			else
			{
				cout << "Please enter a number." << '\n';
			}
		}
	}
	cout << '\n';
	for (i = Int1; i < Int2; i = i + Int3)
	{
		cout << i << endl;

	}
	cout << '\n';

	system("PAUSE");
}

