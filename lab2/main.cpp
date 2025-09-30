#include"string.cpp"

int main(void)
{
    //ЛЕКСИКОГРАФИЧЕСКОЕ СРАВНЕНИЕ СТРОК
//     std::cout<<"\n-=-=-ЛЕКСИКОГРАФИЧЕСКОЕ СРАВНЕНИЕ СТРОК-=-=-"<<std::endl;
//     String str_for_cmp1 = "Привет, Рим";
//     String str_for_cmp2 = "Привет, Мир";
//     std::cout<<'\"'<<str_for_cmp1<<"\" == \""<<str_for_cmp2<<
//     "\" = "<<(str_for_cmp1 == str_for_cmp2)<<std::endl;
//     std::cout<<'\"'<<str_for_cmp1<<"\" != \""<<str_for_cmp2<<
//     "\" = "<<(str_for_cmp1 != str_for_cmp2)<<std::endl;
//     std::cout<<'\"'<<str_for_cmp1<<"\" <  \""<<str_for_cmp2<<
//     "\" = "<< (str_for_cmp1 <  str_for_cmp2)<<std::endl;
//     std::cout<<'\"'<<str_for_cmp1<<"\" >  \""<<str_for_cmp2<<
//     "\" = "<< (str_for_cmp1 >  str_for_cmp2)<<std::endl;
//     std::cout<<'\"'<<str_for_cmp1<<"\" <= \""<<str_for_cmp2<<
//     "\" = "<< (str_for_cmp1 <=  str_for_cmp2)<<std::endl;
//     std::cout<<'\"'<<str_for_cmp1<<"\" >= \""<<str_for_cmp2<<
//     "\" = "<< (str_for_cmp1 >=  str_for_cmp2)<<std::endl;
    

//     //ИНКРЕМЕНТАЦИЯ, ДЕКРЕМЕНТАЦИЯ
//     std::cout<<"\n-=-=-ИНКРЕМЕНТРИВАНИЕ И ДЕКРЕМЕНТИРОВАНИЕ СТРОК-=-=-"<<std::endl;
//     String inc_str = "абвгд123";
//     std::cout<<"Изначальная строка: "<<inc_str<<std::endl;
//     inc_str++;
//     std::cout<<"Инкрементированная строка: "<<inc_str<<std::endl;
//     inc_str--;
//     std::cout<<"Эта же строка, но декрементированная обратно: "<<inc_str<<std::endl;


//     //ВВОД СТРОКИ С КЛАВИАТУРЫ
    String input_str;
//     std::cout<<"\n-=-=-ВВОД СТРОКИ С КЛАВИАТУРЫ-=-=-"<<std::endl;
//     std::cout<<"Введите строку: ";
    std::cin>>input_str;
//     std::cout<<"Введенная строка: "<<input_str<<std::endl;


//     //КОНКАТЕНАЦИЯ
    String str1, str2, str3;

    
//     std::cout<<"\n-=-=-КОНКАТЕНАЦИЯ-=-=-"<<std::endl;
//     std::cout<<"Введите первую строку: ";
    std::cin>>str1;
//     std::cout<<"Введите вторую строку: ";
    std::cin>>str2;


    std::cout << (str3 = (input_str)(1, 3) + " -=-=- " + str2 += str1++) << std::endl<<(str1 == str2++) <<std::endl;
//     str3 = str1 + str2;
//     std::cout<<'\"'<<str1<<"\"+\""<<str2<<"\"=\""<<str3<<'\"'<<std::endl;
    
//     String sscat1 = "Конкатенация - ", sscat2 = "это ";
//     char sscat3[] = "операция склеивания", sscat4[] = "строк";

//     String str4 = sscat1 + sscat2 + sscat3 + " " + sscat4;
//     std::cout << str4 << std::endl;


//     //ПОЛУЧЕНИЕ ПОДСТРОКИ
//     std::cout<<"\n-=-=-ПОЛУЧЕНИЕ ПОДСТРОКИ-=-=-"<<std::endl;
//     std::cout<<"Длина \""<<str4<<"\" = "<<str4.length()<<" символа"<<std::endl;
//     std::cout<<"Подстрока с 19 символа длиной 8 символов: "<<std::endl;
//     String substr = (str4)(19, 8);
//     std::cout<<'\"'<<substr<<'\"'<<std::endl;    

//     String brack_str = "bracket";
//     std::cout<<"3 символ \""<<brack_str<<"\" = "<<brack_str[2]<<std::endl;

}
