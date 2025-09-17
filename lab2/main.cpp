#include"string.cpp"
#include<string>

int main(void)
{
    String str1 = "жаоыдлваоы";
    String str2{"fjmsdlfs"};
    String nullstr;

    char str[] = "fsl;jdflksdjhfksdajlfhsdl";
    char* ptrstr = str; 

    String str3 = nullstr + str1;

    str2 += str1;

    std::cout<<"\'\' + str1 = "<<str3<<std::endl;
    std::cout<<"str2 + str1 = "<<str2<<std::endl;
    std::cout<<"str2[3] = "<<str2[9]<<std::endl;

    std::wstring nigga = L"ф";
    std::cout<<nigga[0]<<std::endl;
}