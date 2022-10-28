#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



char delimiters[] = { ' ','\n','\t','-','+','*','/','>','<','{','}',';',',','(',')','[',']','=' };
char operators[] = { '+','-','*','^','>','<','=' };
char digits[] = { '0','1','2','3','4','5','6','7','8','9' };
char keywords[][10] = {

"if","else","while","do","break","continue","int","double","float","return","char","sizeof","long","short","typedef","switch",
"unsigned","void","static","struct","goto","size_t"

};

bool isDigit(char ch) {

    bool flag = false;
    int i = 0, size = sizeof(digits) / sizeof(char);
    for (int i = 0;i < size;i++) {
        if (ch == digits[i]) {
            flag = true;
            break;
        }
    }

    return flag;

}
// returns true if the character is a delimiter
bool isDelimiter(char ch)
{

    bool flag = false;
    int i = 0, size = sizeof(delimiters) / sizeof(char);

    for (i = 0;i < size;i++)
    {
        if (ch == delimiters[i]) {
            flag = true;
            break;
        }
    }

    return flag;
}

// returns true if the characte is an operator

bool isOperator(char ch)
{
    bool flag = false;
    int i = 0, size = sizeof(operators) / sizeof(char);
    for (i = 0;i < size;i++) {
        if (ch == operators[i]) {
            flag = true;
            break;
        }
    }

    return flag;

}

// returns true if the string is a valid identifier

bool  validIdentifer(char* str)
{
    bool flag = true;
    int i = 0, size = sizeof(digits) / sizeof(char);
    if (isDelimiter(str[0] == true))
        flag = false;
    else {
        for (int i = 0;i < size;i++) {
            if (str[0] == digits[i]) {
                flag = false;
                break;
            }
        }
    }


    return flag;
}


// returns true if the string is a valid keyword

bool isKeyword(char* str)
{

    bool flag = false;
    int total = sizeof(keywords);
    int col = sizeof(keywords[0]);
    int size = total / col;
    size_t i = 0;
    for (i = 0;i < size;i++) {

    //char* str2 = keywords[i];

        if (strcmp(str, keywords[i]) == 0)
        {

            flag = true;
            break;
        }
    }

    return flag;
}



//returns true if the str is a int

bool isRealNumber(char* str)
{

    int i, len = strlen(str);
    bool isDecFound = false;
    bool isNegFound = false;

    if (str[0] == '-' && str[1] == '.')
    {
        isDecFound = true;
        isNegFound = true;
        i = 2;
    }
    else if (str[0] == '.' && str[1] == '-')
    {

        return(false);
    }
    else if (str[0] == '.')
    {

        isDecFound = true;
        i = 1;
    }
    else if (str[0] == '-')
    {
        isNegFound = true;
        i = 1;
    }    
else i = 0;

    bool flag = true;

    for (i;i < len;i++)
    {

        if (str[i] == '-')
        {
            flag = false;
            break;
        }
        else if (str[i] == '.' && isDecFound == true)
        {
            flag = false;
            break;
        }
        else if (str[i] == '.' && isDecFound == false)
        {
            isDecFound = true;
        }
        else if (isDigit(str[i]) == false)
        {

            flag = false;
            break;

        }
    }


    return flag;

}



// returns if the str is an int

bool isInteger(char* str)

{


    int i, len = strlen(str);

    if (str[0] == '-')
    {
        i = 1;
    }
    else i = 0;

    bool flag = true;

    for (i;i < len;i++)
    {

        if (str[i] == '-') {

            flag = false;
            break;
        }

        if (isDigit(str[i]) == false)
        {

            flag = false;
            break;

        }

    }

    return flag;

}

// returns the substring from a str from left
char* subString(char* str, int left, int right)
{

    int i = 0;
    char* substr = (char*)malloc(sizeof(char) * (right - left + 2));

    for (i = left;i <= right;i++)
    {
        substr[i - left] = str[i];
    }

    substr[right - left + 1] = '\0';

    return substr;

}




void parse(char* str)

{

    int left = 0, right = 0;

    int len = strlen(str);



    while (right <= len && left <= right) {

        if (isDelimiter(str[right]) == false)

            right++;



        if (isDelimiter(str[right]) == true && left == right) {

            if (isOperator(str[right]) == true)

                printf("'%c' IS AN OPERATOR\n", str[right]);



            right++;

            left = right;

        }
        else if (isDelimiter(str[right]) == true && left != right

            || (right == len && left != right)) {

            char* subStr = subString(str, left, right - 1);



            if (isKeyword(subStr) == true)

                printf("'%s' IS A KEYWORD\n", subStr);



            else if (isInteger(subStr) == true)

                printf("'%s' IS AN INTEGER\n", subStr);



            else if (isRealNumber(subStr) == true)

                printf("'%s' IS A REAL NUMBER\n", subStr);



            else if (validIdentifer(subStr) == true

                && isDelimiter(str[right - 1]) == false)

                printf("'%s' IS A VALID IDENTIFIER\n", subStr);



            else if (validIdentifer(subStr) == false

                && isDelimiter(str[right - 1]) == false)

                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);

            left = right;

        }

    }

    return;

}


void main() {


     // maximum legth of string is 100 here  

    char str[100] = "float c = .2 ; ";
    char str1[100] = "char ch = 'a';";



    parse(str);
    printf("\n");
    parse(str1); // calling the parse function


}