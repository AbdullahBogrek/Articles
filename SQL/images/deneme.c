// C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Stores the current visiting page 
string current_state_url = ""; 

// Stores url when pressed forward 
stack<string> forward_stack; 

// Stores url when pressed backward 
stack<string> backward_stack; 

// Function for when visit a url 
void visit_new_url(string url) 
{ 
	// If current URL is empty 
	if (current_state_url != "") { 

		// Push into backward_stack 
		backward_stack.push( 
			current_state_url); 
	} 

	// Set curr_state_url to url 
	current_state_url = url; 
} 

// Function to handle state when the 
// forward button is pressed 
void forward() 
{ 
	// If current url is the last url 
	if (forward_stack.empty() 
		|| current_state_url 
			== forward_stack.top()) { 
		cout << "Not Available\n"; 
		return; 
	} 

	// Otherwise 
	else { 

		// Push current state to the 
		// backward steck 
		backward_stack.push( 
			current_state_url); 

		// Set current state to top 
		// of forward stack 
		current_state_url 
			= forward_stack.top(); 

		// Remove from forward stack 
		forward_stack.pop(); 
	} 
} 

// Function to handle state when the 
// backward button is pressed 
void backward() 
{ 
	// If current url is the last url 
	if (backward_stack.empty() || current_state_url == backward_stack.top()) { 

		cout << "Not Available\n"; 
		return; 
	} 

	// Otherwise 
	else { 

		// Push current url to the 
		// forward stack 
		forward_stack.push( 
			current_state_url); 

		// Set current url to top 
		// of backward stack 
		current_state_url 
			= backward_stack.top(); 

		// Pop it from backward stack 
		backward_stack.pop(); 
	} 
} 

// Function that performs the process 
// of pressing forward and backward 
// button in a Browser 
void simulatorFunction() 
{ 
	// Current URL 
	string url = "ajay.com"; 

	// Visit the current URL 
	visit_new_url(url); 

	// Print the current URL 
	cout << "Current URL is: "
		<< current_state_url 
		<< " \n"; 

	// New current URL 
	url = "abc.com"; 

	// Visit the current URL 
	visit_new_url(url); 

	// Print the current URL 
	cout << "Current URL is: "
		<< current_state_url 
		<< " \n"; 

	// Pressed backward button 
	backward(); 

	// Print the current URL 
	cout << "Current URL after pressing"
		<< " Backward button is: "
		<< current_state_url 
		<< " \n"; 

	// Pressed forward button 
	forward(); 

	// Print the current URL 
	cout << "Current URL after pressing"
		<< " Forward button is: "
		<< current_state_url 
		<< " \n"; 

	// New current URL 
	url = "nikhil.com"; 

	// Visit the current URL 
	visit_new_url(url); 

	// Print the current URL 
	cout << "Current URL is: "
		<< current_state_url 
		<< " \n"; 

	// Pressed forward button 
	forward(); 

	// Print the current URL 
	cout << "Current URL after pressing"
		<< " Forward button is: "
		<< current_state_url 
		<< " \n"; 
	// Pressed backward button 
	backward(); 

	// Print the current URL 
	cout << "Current URL after pressing"
		<< " Backward button is: "
		<< current_state_url 
		<< " \n"; 
} 

// Driver Code 
int main() 
{ 
	// Function to simulate process of 
	// pressing forward & backward button 
	simulatorFunction(); 
} 

