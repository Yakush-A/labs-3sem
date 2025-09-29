#include"string.cpp"
#include<string>
#include<cstdint>
int main(void)
{

    char32_t nigger = U'🥵';
    String nigga = "нигга";
    std::cout<<nigga<<" len = "<<nigga.length()<<std::endl;
    std::cout<<nigga<<" size = "<<nigga.size()<<std::endl;

    std::cout<< std::hex << static_cast<uint32_t>(nigger)<<std::endl;







    //СОЗДАНИЕ СТРОКИ ИЗ МАССИВА СИМВОЛОВ
    char ss[] = "Строка для примера";
    char* ptr = ss; 
    
    String char_array_str = ss;
    String char_ptr_str = ptr;
    String another_string_str = char_array_str;

    std::cout<<"Строка образованная из стат. массива символов: \""<<char_array_str<<'\"'<<std::endl;
    std::cout<<"Строка образованная по указателю на массив символов: \""<<char_ptr_str<<'\"'<<std::endl;
    std::cout<<"Строка образованная из другой строки: \""<<another_string_str<<'\"'<<std::endl;


    //ЛЕКСИКОГРАФИЧЕСКОЕ СРАВНЕНИЕ СТРОК
    std::cout<<"-=-=-ЛЕКСИКОГРАФИЧЕСКОЕ СРАВНЕНИЕ СТРОК-=-=-"<<std::endl;
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
    std::cout<<"-=-=-ВВОД СТРОКИ С КЛАВИАТУРЫ-=-=-"<<std::endl;
    std::cout<<"Введите строку: ";
    std::cin>>input_str;
    std::cout<<"Введенная строка: "<<input_str<<std::endl;


    //КОНКАТЕНАЦИЯ
    String str1, str2, str3;
    std::cout<<"-=-=-КОНКАТЕНАЦИЯ-=-=-"<<std::endl;
    std::cout<<"Введите первую строку: ";
    std::cin>>str1;
    std::cout<<"Введите вторую строку: ";
    std::cin>>str2;
    str3 = str1 + str2;
    std::cout<<'\"'<<str1<<"\"+\""<<str2<<"\"=\""<<str3<<'\"'<<std::endl;
    
    String str4 = str3 + " еще слово)" + " опа еще одно";
    std::cout<<str4<<std::endl;
}