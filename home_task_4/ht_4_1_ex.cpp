#include <iostream>
#include <string>

using namespace std;

const int kNumberOfActorsOnStage = 7;
const int kNumberOfPerformances = 3;

  string declensionOfNum(int year)
{
    if((year / 10) % 10 == 1) return " лет";
    else if(year % 10 > 4 || year % 10 == 0) return " лет";
    else if(year % 10 == 1) return " год";
    else return " года";
}


struct Actor {
    string name;
    string surname;
    int WorkExperience;
    struct Performance** schedule;
};

struct Performance {
    string NameOfPerformance;
    int begining_hour;
    Actor* participants[kNumberOfActorsOnStage];
    int participants_num;
};

int main() {
    Performance WoeFromWit = {"Горе от ума", 13, {0}, 0 };
    Performance TheAdneturesOfTomSawyer = {"Приключения Тома Сойера", 17, {0}, 0 };
    Performance TheMasterAndMargarita = {"Мастер и Маргарита", 19, {0}, 0 };
    Performance performance_list[] = {WoeFromWit, TheAdneturesOfTomSawyer, TheMasterAndMargarita};

    cout << "Введите количество актёров, участвующих в спектакле: ";
    int actors_num;
    cin >> actors_num;

    Actor* actor_list = new Actor[actors_num];

    cout << "Введите информацию об актёрском составе: " << endl;
    for (int i = 0; i < actors_num; i++) {
        cout << "Актёр " << i + 1 << endl;

        cout << "Имя актёра : ";
        cin >> actor_list[i].name;

        cout <<"Фамилия актёра : ";
        cin >> actor_list[i].surname;

        cout << "Стаж работы актёра: ";
        cin >> actor_list[i].WorkExperience;

        cout << "Количество спектаклей : ";
        int Performances_num;
        cin >> Performances_num;
        actor_list[i].schedule = new Performance* [Performances_num];
        for (int j = 0; j < Performances_num; j++) {
            cout << "Введите '0', если актёр выступает в спектакле 'Горе от ума', '1', если актёр выступает в спектакле 'Приключения Тома Сойера', '2', если актёр выступает в спектакле 'Мастер и Маргарита': ";
            int Performance;
            cin >> Performance;
            actor_list[i].schedule[j] = performance_list + Performance;
            performance_list[Performance].participants[performance_list[Performance].participants_num++] = &actor_list[i];
        }

        cout << endl;

    }
    cout << "Здесь вы можете посмотреть расписание спектаклей: " << endl;
    for (int i = 0; i < kNumberOfPerformances; i++) {
        cout << i + 1 << ". " << performance_list[i].NameOfPerformance << ", ";
        cout << performance_list[i].begining_hour << ":00" << endl;
        cout << "Актёрский состав: " << endl;
        for (int j = 0; j < performance_list[i].participants_num; j++) {
            cout << "  " << j + 1 << ") " << performance_list[i].participants[j]->name << " ";
            cout << " " << performance_list[i].participants[j]->surname << ", ";
            cout <<" профессиональный стаж: " << performance_list[i].participants[j]->WorkExperience << declensionOfNum(actor_list[i].WorkExperience)<< endl;
        }
        cout << endl;
    }
}
