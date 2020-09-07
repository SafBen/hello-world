#include <iostream>
#include <string>

bool isPalindrome(std::string s){
	// test si la chaine est vide
	if (s.size()==0||s==" ")
	{
		std::cout << "false\n";
		return false;
	}
	for (int i = 0; i < s.size()/2; i++)
	{
		if (s[i]!=s[s.size()-i-1])
		{
			std::cout << "false\n";
			return true;
		}
	}
	std::cout << "true\n";
}

int main(){
	std::string s1="test";
	std::string s2="";
	std::string s3=" ";
	std::string s4="kayak";
	isPalindrome(s1);
	isPalindrome(s2);
	isPalindrome(s3);
	isPalindrome(s4);
	return 0;
}