#include <iostream>
#include <string>


const int kNumberOfActorsOnStage = 7;
const int kNumberOfPerformances = 3;

  std::string declensionOfNum(int year)
{
    if((year / 10) % 10 == 1) return " лет";
    else if(year % 10 > 4 || year % 10 == 0) return " лет";
    else if(year % 10 == 1) return " год";
    else return " года";
}


struct Actor {
    std:: string name;
    std:: string surname;
    int WorkExperience;
    struct Performance** schedule;
};

struct Performance {
    std::string NameOfPerformance;
    int begining_hour;
    Actor* participants[kNumberOfActorsOnStage];
    int participants_num;
};

int main() {
    Performance WoeFromWit = {"Горе от ума", 13, {0}, 0 };
    Performance TheAdneturesOfTomSawyer = {"Приключения Тома Сойера", 17, {0}, 0 };
    Performance TheMasterAndMargarita = {"Мастер и Маргарита", 19, {0}, 0 };
    Performance performance_list[] = {WoeFromWit, TheAdneturesOfTomSawyer, TheMasterAndMargarita};

    std::cout << "Введите количество актёров, участвующих в спектакле: ";
    int actors_num;
    std::cin >> actors_num;

    Actor* actor_list = new Actor[actors_num];

    std::cout << "Введите информацию об актёрском составе: \n";
    for (int i = 0; i < actors_num; i++) {
        std::cout << "Актёр " << i + 1<<" \n" ;

        std::cout << " Имя актёра : ";
        std::cin >> actor_list[i].name;

        std::cout <<" Фамилия актёра : ";
        std::cin >> actor_list[i].surname;

        std::cout << " Стаж работы актёра: ";
        std::cin >> actor_list[i].WorkExperience;

        std::cout << " Количество спектаклей сегодня: ";
        int Performances_num;
        std::cin >> Performances_num;
        actor_list[i].schedule = new Performance* [Performances_num];
        for (int j = 0; j < Performances_num; j++) {
            std::cout << "Введите '0', если актёр выступает в спектакле 'Горе от ума', '1', если актёр выступает в спектакле 'Приключения Тома Сойера', '2', если актёр выступает в спектакле 'Мастер и Маргарита': ";
            int Performance;
            std::cin >> Performance;
            actor_list[i].schedule[j] = performance_list + Performance;
            performance_list[Performance].participants[performance_list[Performance].participants_num++] = &actor_list[i];
        }

        std::cout <<"\n";

    }
    std::cout << "Здесь вы можете посмотреть расписание спектаклей: \n" ;
    for (int i = 0; i < kNumberOfPerformances; i++) {
        std::cout << "\n"<<i + 1 << ". Название спектакля: << " << performance_list[i].NameOfPerformance << " >>\n";
        std::cout <<"   Время начала: "<< performance_list[i].begining_hour << ":00 \n" ;
        std::cout << "   Актёрский состав:" ;
        for (int j = 0; j < performance_list[i].participants_num; j++) {
            std::cout << "  \n   " << j + 1 << ") " << performance_list[i].participants[j]->name << "";
            std::cout << " " << performance_list[i].participants[j]->surname << ", \n    ";
            std::cout <<"  Профессиональный стаж: " << performance_list[i].participants[j]->WorkExperience << declensionOfNum(actor_list[i].WorkExperience);
        }
        std::cout << "\n";
    }
}
