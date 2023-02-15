//Письмо другу
#include "std_lib_facilities.h"

int main(){

	cout << "Введите имя адресата: ";
	string first_name;
	cin >> first_name;

	cout << "\nПривет, " << first_name << "!\n"
		<< "Как у тебя дела?\n"
		<< "Чем занимается тетушка Элли?\n"
		<< "Как здоровье у дяди Генри?\n\n";

	string friend_name;
	cout << "Введите имя друга: ";
	cin >> friend_name;

	cout << "\nДавно ли ты встречал " << friend_name << "?\n";

	char friend_sex = 0;
	
	cout << "\nВедите пол друга: ";
	cin >> friend_sex;

	if ('m' == friend_sex)
		cout << "Если ты увидишь " << friend_name
			<< " пожалуйста попроси его позвонить мне.\n";

	if ('f' == friend_sex)
		cout << "Если ты увидишь " << friend_name
			<< " пожалуйста попроси ее позвонить мне.\n";

	int age = 0;

	cout << "Введите возраст адресата: ";
	cin >> age;

	if (age <= 0 or age >= 110)
		simple_error("ты шутишь!");

	if (age < 12)
		cout << "На следующий год тебе исполнится " << age+1 << " лет.\n";

	if (age == 17)
		cout << "В следющем году ты сможешь голосовать." << endl;

	if (age > 70)
		cout << "Надеюсь, что ты не скучаешь на пенсии." << endl;

	cout << "Искренне твой,\n";
	cout << endl << endl;
	cout << "Andrey." << endl;
	

		
	


		return 0;
}
