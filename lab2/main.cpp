#include"string.cpp"
#include<string>
int main(void)
{
    //СОЗДАНИЕ СТРОКИ ИЗ МАССИВА СИМВОЛОВ
    char ss[] = "Строка для примера";
    char* ptr = ss; 
    
    String char_array_str = ss;
    String char_ptr_str = ptr;

    std::cout<<"Строка образованная из стат. массива символов: \""<<char_array_str<<'\"'<<std::endl;
    std::cout<<"Строка образованная по указателю на массив символов: \""<<char_ptr_str<<'\"'<<std::endl;


    //ЛЕКСИКОГРАФИЧЕСКОЕ СРАВНЕНИЕ СТРОК
    String str_for_cmp1 = "Привет, Рим";
    String str_for_cmp2 = "Привет, Мир";

    std::cout<<'\"'<<str_for_cmp1<<"\" == \""<<str_for_cmp2<<
    "\" = "<<((str_for_cmp1 == str_for_cmp2) ? "true" : "false")<<std::endl;
    std::cout<<'\"'<<str_for_cmp1<<"\" != \""<<str_for_cmp2<<
    "\" = "<<((str_for_cmp1 != str_for_cmp2) ? "true" : "false")<<std::endl;
    std::cout<<'\"'<<str_for_cmp1<<"\" < \""<<str_for_cmp2<<
    "\" = "<< ((str_for_cmp1 <  str_for_cmp2) ? "true" : "false")<<std::endl;
    std::cout<<'\"'<<str_for_cmp1<<"\" > \""<<str_for_cmp2<<
    "\" = "<< ((str_for_cmp1 >  str_for_cmp2) ? "true" : "false")<<std::endl;


    //ВВОД СТРОКИ С КЛАВИАТУРЫ
    String input_str;
    std::cout<<"Введите строку: ";
    std::cin>>input_str;
    std::cout<<"Введенная строка: "<<input_str<<std::endl;


    //КОНКАТЕНАЦИЯ
    String str1, str2, str3;
    std::cout<<"Склеивание строк:"<<std::endl;
    std::cout<<"Введите первую строку: ";
    std::cin>>str1;
    std::cout<<"Введите вторую строку: ";
    std::cin>>str2;
    str3 = str1;
    str3+= str2;
    std::cout<<'\"'<<str1<<"\"+\""<<str2<<"\"=\""<<str3<<'\"'<<std::endl;
    
}