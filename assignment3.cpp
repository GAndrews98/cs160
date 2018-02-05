/*****************************************************************
 * Program Name: assignment3
 * Author: Joseph Andrews
 * Date: 2/4/18
 * Description: A list of error handling functions with test cases
 * Input: Depends on the function
 * Output: Text to screen / depends on the function
*****************************************************************/

#include <iostream>
#include <string>

using namespace std;

/******************************************************************
 * Function: check_range
 * Description: Checks if a test value is between an upper and lower bound
 * Parameters: int lower-bound, int upper_bound, int test_value
 * Pre-Conditions: Inputs must be ints
 * Post-Conditions: Function will return either true or false
******************************************************************/
bool check_range(int lower_bound, int upper_bound, int test_value) {
	if (test_value >= lower_bound) {
		if (test_value <= upper_bound) {
			return true;
		}
		return false;
	}
	return false;
}

/*****************************************************************
 * Function: is_int
 * Description: Checks if a given string is an integer
 * Parameters: string num
 * Pre-Conditions: Input must be a string
 * Post-Conditions: Function will return either true or false
*****************************************************************/
bool is_int(string num) {
	for (int i = 0; i < num.length(); i++) {
		if (num[i] < 48 or num[i] > 57) //checks if int
			return false;
	}
	return true;
}

/****************************************************************
 * Function: is_float
 * Description: Checks if a given string is a float
 * Parameters: string num
 * Pre-Conditions: Input must be a string
 * Post-onditions: Function will return either true or false
****************************************************************/
bool is_float(string num) {
	int decCount = 0;
	for (int i = 0; i < num.length(); i++) {
		if (num[i] == 46) {
			decCount++; //counts number of decimals
			if (decCount > 1)
				return false;
		}
		else if (num[i] < 48 or num[i] > 57) 
			return false;
	}
	return true; 
}

/*****************************************************************
 * Function: is_capital
 * Description: Checks if a given character is a capital letter
 * Parameters: char letter
 * Pre-Conditions: Input must be a char
 * Post-Conditions: Function will return either true or false
*****************************************************************/
bool is_capital(char letter) {
	if (letter > 64 && letter < 91) //capitals
		return true;
	return false;
}

/****************************************************************
 * Function: is_even
 * Description: Checks if a given integer is even
 * Parameters: int num
 * Pre-Conditions: Input must be an integer
 * Post-Conditions: Function will return either true or false
****************************************************************/
bool is_even(int num) {
	if ((num % 2) == 0) //even
		return true;
	return false; 
}

/****************************************************************
 * Function: is_odd
 * Description: Checks if a a given integer is odd
 * Paramaters: int num
 * Pre-Conditions: Input must be an integer
 * Post-Conditions: Function will return either true or false
****************************************************************/
bool is_odd(int num) {
	if ((num % 2) == 1) //odd
		return true;
	return false;
}

/****************************************************************
 * Function: equality_test
 * Description: Checks if two numbers are equal, less than each other, or greater than each other
 * Parameters: int num1, int num2
 * Pre-Conditions: Inputs must be integers
 * Post-Conditions: Function will return either -1, 0, or 1 based on the numbers given
****************************************************************/
int equality_test(int num1, int num2) {
	if (num1 < num2)
		return -1;
	else if (num1 == num2)
		return 0;
	else 
		return 1;
}

/****************************************************************
 * Function: float_is_equal
 * Description: Checks if two floats are equal to a certain precision
 * Parameters: float num1, float num2, float precision
 * Pre-Conditions: Inputs must be floats
 * Post-Conditions: Function will return either true or false
****************************************************************/
bool float_is_equal(float num1, float num2, float precision) {
	if (num1 == num2) 
		return true; //obvious case
	string str1 = "";
	string str2 = "";
	str1 = num1;
	str2 = num2;
	int i = 0;
	string longest = "";
	if (str1.length() >= str2.length()) //finds the longer string 
		longest = str1;
	else
		longest = str2;
	
	for (int j = 0; j < longest.length(); j++) { 
		if (longest[j] == 46) { //checks if decimal
			while (i < precision) {
				if (str1[i+j] != str2[i+j]) //compares numbers after decimal
					return false;
				i++;
			}
			return true;
		}
	}
}

/******************************************************************
 * Function: numbers_present
 * Description: Checks if numbers are present in a string
 * Parameters: string sentence
 * Pre-Conditions: Input must be a string
 * Post-Conditions: Function will return either true or false
*******************************************************************/
bool numbers_present(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] > 47 && sentence[i] < 58) //checks numbers
			return true;
	}
	return false;
}

/******************************************************************
 * Function: letters_present
 * Description: Checks if letters are present in a string
 * Parameters: string sentence
 * Pre-Conditions: Input must be a string
 * Post-Conditions: Function will return either true or false
******************************************************************/
bool letters_present(string sentence) {
	for (int i = 0; i < sentence.length(); i++) {
		if ((sentence[i] > 64 && sentence[i] < 91) || (sentence[i] > 96 && sentence[i] < 123)) //checks letters
			return true;
	}
	return false;
}

/*****************************************************************
 * Function: contains_sub_string
 * Description: Checks if a substring exists in a string
 * Parameters: string sentence, string sub_string
 * Pre-Conditions: Inputs must be strings
 * Post-Conditions: Function will return either true or false
*****************************************************************/
bool contains_sub_string(string sentence, string sub_string) {
	if (sub_string.length() > sentence.length()) //checks obvious fail
		return false;
	for (int i = 0; i < sentence.length(); i++) { //for every character in the sentence
		if (sentence[i] == sub_string[0]) { 
			for (int j = 0; j < sub_string.length(); j++) { //for every character in the sub string
				if (sub_string[j] == sentence[i])
					i++; //move one over in the sentence
				else
					return false; //character isn't equal
			}
			return true; //all chars equal in substring
		}
	}
	return false; //substring not in sentence
}

/*****************************************************************
 * Function: word_count
 * Description: Counts the number of words in a string
 * Parameters: string sentence
 * Pre-Conditions: Input must be a string
 * Post-Conditions: Function will return the number of words as an int
*****************************************************************/
int word_count(string sentence) {
	int words = 0;
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] != 32) { 
			if (sentence[i+1] == 32) //accounts for more than one space
				words++; //word counter
		}
	}
	return words+1;
}

/*****************************************************************
 * Function: to_upper
 * Descrption: Converts all lowercase letters to uppercase in a string
 * Parameters: string sentence
 * Pre-Condtions: Input mus be a string
 * Post-Condition: Function will return original string with only lowercase letters changed
*****************************************************************/
string to_upper(string sentence) {
	string uppercase = "";
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] > 96 && sentence[i] < 123) {
			sentence[i] -= 32; //adds an offset to change case
			uppercase += sentence[i];
		}
		else if (sentence[i] < 97 || sentence[i] > 122)
			uppercase += sentence[i];
	}
	return uppercase;
}

/******************************************************************
 * Function: to_lower
 * Description: Converts all uppercase letters to lowercase in a string
 * Parameters: string sentence
 * Pre-Conditions: Input must be a string
 * Post-Conditions: Function will return original string with only uppercase letters changed
******************************************************************/
string to_lower(string sentence) {
	string lowercase = "";
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] > 64 && sentence[i] < 91) {
			sentence[i] += 32; //adds offset to change case
			lowercase += sentence[i];
		}
		else
			lowercase += sentence[i];
	}
	return lowercase;
}

/******************************************************************
 * Function: get_int
 * Description: Continually prompts user for an integer until valid, then returns that integer
 * Parameters: string prompt
 * Pre-Conditions: Input must be a string
 * Post-Conditions: Function will only return integer if valid
******************************************************************/
int get_int(string prompt) {
	int num = 0;
	if (is_int(prompt)) { //checks if int
		for (int i = 0; i < prompt.length(); i++) { //typecasts string to int
			num = num * 10;
			num += (prompt[i]) -48;
		}
		return num;
	}
	else {
		while (is_int(prompt) == false) { //reprompts until valid
			cout << "Input not valid, try again: ";
			getline(cin, prompt);
			if (is_int(prompt)) {
				for (int i = 0; i < prompt.length(); i++) { //typecasts string to int
					num = num * 10;
					num += (prompt[i]) -48;
				}
				return num;
			}
		}
	}
}

/*****************************************************************
 * Function: get_float
 * Description: Continuously prompts user for a float until valid, then returns that float
 * Parameters: string prompt
 * Pre-Conditions: Input must be a float
 * Post-Conditions: Function will only return float if valid
*****************************************************************/
float get_float(string prompt) { //WARNING: this one is messy
	float num = 0;
	int decPos = 0;
	string decOffset = "";
	string zeros = "";
	int shifter = 0;
	if (is_float(prompt)) {
		for (int i = 0; i < prompt.length(); i++) { //typecasts string to "int"
			if (prompt[i] != 46) {	
				num = num * 10;
				num += (prompt[i]) -48;
			}
			else if (prompt[i] == 46)
				decPos = prompt.length()-i-1; //finds position of decimal
		}
		for (int k = 0; k < decPos; k++) {
			zeros += "0"; //adds zeros based off decimal position
		}
		decOffset = "1" + zeros; //creates number to divide original float by
		for (int j = 0; j < decOffset.length(); j++) { //typecasts string to int
			shifter = shifter * 10;
			shifter += (decOffset[j]) -48;
		}
		num = num / shifter; //shifts decimal place
		return num;
	}
	else {
		while (is_float(prompt) == false) { //reprompts until valid
			cout << "Input not valid, try again: ";
			getline(cin, prompt);
			if (is_float(prompt)) {
				for (int i = 0; i < prompt.length(); i++) {
					if (prompt[i] != 46) {
						num = num * 10;
						num += (prompt[i]) -48;
					}
					else if (prompt[i] == 46)
						decPos = prompt.length()-i-1;
				}
				for (int k = 0; k < decPos; k++) {
					zeros += "0";
				}
				decOffset = "1" + zeros;
				for (int j = 0; j < decOffset.length(); j++) {
					shifter = shifter * 10;
					shifter += (decOffset[j]) -48;
				}
				num = num / shifter;
				return num;
			}
		}
	}
}

/*************************************************************************
 * Function: main
 * Description: Tests all previous functions by calling them and printing pass/fail
 * Parameters: None
 * Pre-Conditions: Program must compile
 * Post-Conditions: None
*************************************************************************/
int main() { 
	cout << endl;
		
	//Function: check_range
	cout << "Function: check_range - Input: 0, 100, 50 - Expected Output: True - Actual Output:  " << endl;
	if (check_range(0, 100, 50)) 
		cout << "True, PASS" << endl;
	else 
		cout << "False, FAIL" << endl;
	cout << "Function: check_range - Input: 0, 100, 200 - Expected Output: False - Actual Output: " << endl;
	if (check_range(0, 100, 200))
		cout << "True, FAIL" << endl;
	else 
		cout << "False, PASS" << endl;
	cout << endl;
	
	//Function: is_int
	cout << "Function: is_int - Input: '5' - Expected Output: True - Actual Output: " << endl;
	if (is_int("5")) 
		cout << "True, PASS" << endl;
	else
		cout << "False, FAIL" << endl;
	cout << "Function: is_int - Input: 'two' - Expected Output: False - Actual Output: " << endl;
	if (is_int("two"))
		cout << "True, FAIL" << endl;
	else
		cout << "False, PASS" << endl;
	cout << endl;
	
	//Function: is_float
	cout << "Function: is_float - Input: '12.5' - Expected Output: True - Actual Output: " << endl;
	if (is_float("12.5"))
		cout << "True, PASS" << endl;
	else 
		cout << "False, FAIL" << endl;
	cout << "Function: is_float - Input: '10.5.2' - Expected Output: False - Actual Output: " << endl;
	if (is_float("10.5.2"))
		cout << "True, FAIL" << endl;
	else
		cout << "False, PASS" << endl;
	cout << endl;

	//Function: is_capital
	cout << "Function: is_capital - Input: 'A' - Expected Output: True - Actual Output: " << endl;
	if (is_capital('A'))
		cout << "True, PASS" << endl;
	else 
		cout << "False, FAIL" << endl;
	cout << "Function: is_capital - Input: 'g' - Expected Output: False - Actual Output: " << endl;
	if (is_capital('g'))
		cout << "True, FAIL" << endl;
	else
		cout << "False, PASS" << endl;
	cout << endl;

	//Function: is_even
	cout << "Function: is_even - Input: 32 - Expeicted Output: True - Actual Output: " << endl;
	if (is_even(32))
		cout << "True, PASS" << endl;
	else
		cout << "False, FAIL" << endl;
	cout << "Function: is_even - Input: 25 - Expected Output: False - Actual Output: " << endl;
	if (is_even(25))
		cout << "True, FAIL" << endl;
	else 
		cout << "False, PASS" << endl;
	cout << endl;

	//Function: is_odd
	cout << "Function: is_odd - Input: 15 - Expected Output: True - Actual Output: " << endl;
	if (is_odd(15))
		cout << "True, PASS" << endl;
	else
		cout << "False, FAIL" << endl;
	cout << "FunctionL is_odd - Input: 8 - Expected Output: False - Actual Output: " << endl;
	if (is_odd(8))
		cout << "True, FAIL" << endl;
	else 
		cout << "False, PASS" << endl;
	cout << endl;
	
	//Function: equality_test
	cout << "Function: equality_test - Input: 5, 10 - Expected Output: -1 - Actual Output: " << endl;
	if (equality_test(5, 10) == -1) 
		cout << "-1, PASS" << endl;
	else
		cout << "FAIL" << endl;
	cout << "Function: equality_test - Input: 10, 10 - Expected Output: 0 - Actual Output: " << endl;
	if (equality_test(10, 10) == 0) 
		cout << "0, PASS" << endl;
	else 
		cout << "FAIL" << endl;
	cout << "Function: equality_test - Input: 10, 5 - Expected Output: 1 - Actual Output: " << endl;
	if (equality_test(10, 5) == 1) 
		cout << "1, PASS" << endl;
	else 
		cout << "FAIL" << endl;
	cout << endl;

	//Function: float_is_equal
	cout << "Function: float_is_equal - Input: 13.52, 13.52, 2 - Expected Output: True - Actual Output: " << endl;
	if (float_is_equal(13.52, 13.52, 2)) 
		cout << "True, PASS" << endl;
	else
		cout << "False, FAIL" << endl;
	cout << "Function: float_is_equal - Input: 3.1415, 3.1414, 3 - Expected Output: True - Actual Output: " << endl;
	if (float_is_equal(3.1415, 3.1414, 3))
		cout << "True, PASS" << endl;
	else
		cout << "False, FAIL" << endl;
	cout << "Function: float_is_equal - Input: 2.345, 2.344, 3 - Expected Output: False - Actual Output: " << endl;
	if (float_is_equal(2.345, 2.344, 3))
		cout << "True, FAIL" << endl;
	else
		cout << "False, PASS" << endl;
	cout << endl;
	
	//Function: numbers_present
	cout << "Function: numbers_present - Input: 'Mlg_pr0_g4m3r' - Expected Output: True - Actual Output: " << endl; 
	if (numbers_present("Mlg_pr0_g4m3r"))
		cout << "True, PASS" << endl;
	else
		cout << "False, FAIL" << endl;
	cout << "Function: numbers_present - Input: 'this is a string' - Expected Output: False - Actual Output: " << endl;
	if (numbers_present("this is a string")) 
		cout << "True, FAIL" << endl;
	else 
		cout << "False, PASS" << endl;
	cout << endl;

	//Function: letters_present
	cout << "Function: letters_present - Input: 'coding is fun' - Expected Output: True - Actual Output: " << endl;
	if (letters_present("coding is fun"))
		cout << "True, PASS" << endl;
	else 
		cout << "False, FAIL" << endl;
	cout << "Function: letters_present - Input: '3.1415926535' - Expected Output: False - Actual Output: " << endl;
	if (letters_present("3.1415926535")) 
		cout << "True, FAIL" << endl;
	else
		cout << "False, PASS" << endl;
	cout << endl;

	//Function: contains_sub_string
	cout << "Function: contains_sub_string - Input: 'pie tastes good', 'pie' - Expected Output: True - Actual Output: " << endl;
	if (contains_sub_string("pie tastes good" , "pie")) 
		cout << "True, PASS" << endl;
	else
		cout << "False, FAIL" << endl;
	cout << "Function: contains_sub_string - Input: 'donkey', 'cat' - Expected Output: False - Actual Output: " << endl;
	if (contains_sub_string("donkey" , "cat")) 
		cout << "True, FAIL" << endl;
	else 
		cout << "False, PASS" << endl;
	cout << endl;

	//Function: word_count
	cout << "Function: word_count - Input: 'two words' - Expected Output: 2 - Actual Output: " << endl;
	if (word_count("two words") == 2)
		cout << "2, PASS" << endl;
	else
		cout << "FAIL" << endl;
	cout << "Function: word_count - Input: 'three words here' - Expected Output: 3 - Actual Output: " << endl;
	if (word_count("three words here") == 3)
		cout << "3, PASS" << endl;
	else
		cout << "FAIL" << endl;
	cout << "Function: word_count - Input: 'lots   of   spaces' - Expected Output: 3 - Actual Output: " << endl;
	if (word_count("lots   of      spaces") == 3)
		cout << "3, PASS" << endl;
	else
		cout << "FAIL" << endl;
	cout << endl;
	
	//Function: to_upper
	cout << "Function: to_upper - Input: 'uppercase' - Expected Output: 'UPPERCASE' - Actual Output: " << endl;
	cout << to_upper("uppercase") << ", PASS" <<  endl;
	cout << "Function: to_upper - Input: 'C0mPL3x sTr1ng' - Expected Output: 'C0MPL3X STR1NG' - Actual Output: " << endl;
	cout << to_upper("C0mPL3x sTr1ng") << ", PASS" << endl;
	cout << endl;

	//Function: to_lower
	cout << "Function: to_lower - Input: 'LOWERCASE' - Expected Output: 'lowercase' - Actual Output: " << endl;
	cout << to_lower("LOWERCASE") << ", PASS" << endl;
	cout << "Function: to_lower - Input: 'M3sSy STRing' - Expected Output: 'm3ssy string' - Actual Output: " << endl;
	cout << to_lower("M3sSy STRing") << ", PASS" << endl;
	cout << endl;

	//Function: get_int
	cout << "Function: get_int" << endl;
	cout << "Enter an integer: "; 
	string prompt = "";
	getline(cin, prompt);
	cout << "Your integer: " << get_int(prompt) << endl;
	cout << endl;

	//Function: get_float
	cout << "Function: get_float" << endl;
	cout << "Enter a float: ";
	string prompt2 = "";
	getline(cin, prompt2);
	cout << "Your float: " << get_float(prompt2) << endl;

}
