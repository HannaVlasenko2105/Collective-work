#include <stdio.h>
#include <string.h>

struct User {
  char username[100];
  char password[100];
  char name[100];
  char email[100];
  char number[50];
};

struct Order {
  char type[50];
  char address[100];
  char city[50];
  int floor, area;
  float price;
  int months;
};

struct ApartmentsInfo {
  char type[50];
  char address[100];
  char city[50];
  int floor, area;
  float price;
};

struct ApartmentsInfo apartments[10];

struct User newUser;

struct Order orders[10];
int orderCount = 0;

void createAccount(){
  printf("\n-------Створення нового акаунту------\n");
  printf("\nВведіть своє ім'я користувача: ");
  scanf("%s", newUser.username);
  printf("Введіть свій пароль: ");
  scanf("%s", newUser.password);
  printf("Введіть своє ім'я: ");
  scanf("%s", newUser.name);
  printf("Введіть свою електронну адресу: ");
  scanf("%s", newUser.email);
  printf("Введіть свій номер телефону: ");
  scanf("%s", newUser.number);
  printf("\nАкаунт успішно створено!\n");
  printf("-------------------------------------\n");
}

void login() {
  char username[100];
  char password[100];
  printf("\n-----------Вхід в систему------------\n");
  printf("\nВведіть своє ім'я користувача: ");
  scanf("%s", username);
  if (strcmp(username, newUser.username) != 0) {
    printf("Неправильне ім'я користувача.\n");
  } else {
    printf("Введіть свій пароль: ");
    scanf("%s", password);
    if (strcmp(password, newUser.password) != 0) {
      printf("Неправильний пароль.\n");
    } else {
      printf("Увійшли як %s.\n", username);
    }
  }
  printf("-------------------------------------\n");
}

void viewAccountInfo(struct User newUser) {

  int userOrdersCount = 0;
  for (int i = 0; i < orderCount; i++) {
    if (orders[i].months > 0) {
      userOrdersCount++;
    }
  }

  printf("\n--------------Ваш акаунт-------------\n");
  printf("Ім'я користувача: %s\n", newUser.username);
  printf("Пароль: %s\n", newUser.password);
  printf("Ім'я: %s\n", newUser.name);
  printf("Електронна пошта: %s\n", newUser.email);
  printf("Номер телефону: %s\n", newUser.number);
  printf("Кількість замовлень: %d\n", userOrdersCount);
  printf("-------------------------------------\n");
}

void changeMonths() {
  int orderNumber;
  int newDuration;
  int choice;

  printf("Введіть номер замовлення: ");
  scanf("%d", &orderNumber);

  orderNumber--;

  if (orderNumber < 0 || orderNumber >= orderCount) {
      printf("Невірний номер замовлення.\n");
      return;
  }

  printf("Введіть нову тривалість оренди (у місяцях): ");
  scanf("%d", &newDuration);

  printf("Ви бажаєте змінити тривалість оренди для замовлення №%d на %d місяців?\n", orderNumber + 1, newDuration);
  printf("(1 - Так/0 - Ні)\n");
  printf("Ваш вибір: ");
  scanf("%d", &choice);

  if (choice == 1) {
      orders[orderNumber].months = newDuration;
      printf("Тривалість оренди для замовлення №%d була змінена на %d місяців.\n", orderNumber + 1, newDuration);
  } else if (choice == 0) {
      printf("Тривалість оренди для замовлення №%d не була змінена.\n", orderNumber + 1);
  } else {
      printf("Невірний вибір. Будь ласка, введіть 1 або 0.\n");
  }
}

void cancelOrder() {
  int orderNumber;
  int choice;

  printf("Введіть номер замовлення: ");
  scanf("%d", &orderNumber);
  orderNumber--;

  if (orderNumber < 0 || orderNumber >= orderCount) {
      printf("Невірний номер замовлення.\n");
      return;
  }

  printf("Ви бажаєте скасувати замовлення №%d?\n", orderNumber + 1);
  printf("(1 - Так/0 - Ні)\n");
  printf("Ваш вибір: ");
  scanf("%d", &choice);

  if (choice == 1) {
      orders[orderNumber].months = 0;
      printf("Замовлення №%d було скасовано.\n", orderNumber + 1);
  } else if (choice == 0) {
      printf("Замовлення №%d не було скасовано.\n", orderNumber + 1);
  } else {
      printf("Невірний вибір. Будь ласка, введіть 1 або 0.\n");
  }
}

void viewOrders() {
  printf("-----------Ваші замовлення-----------\n");

  for (int i = 0; i < orderCount; i++) {
  if (orders[i].months == 0) continue;

    printf("Замовлення %d\n", i + 1);
    printf("Тип: %s\n", orders[i].type);
    printf("Адреса: %s\n", orders[i].address);
    printf("Місто: %s\n", orders[i].city);
    printf("Поверх: %d\n", orders[i].floor);
    printf("Площа: %d\n", orders[i].area);
    printf("Ціна за місяць: %.2f\n", orders[i].price);
    printf("Місяців оренди: %d\n", orders[i].months);
    float totalCost = orders[i].price * orders[i].months;
    printf("Загальна вартість за %d місяців: %.2f\n", orders[i].months,
           totalCost);
    printf("\n");
  }
  
  if (orderCount == 0) {
    printf("Поточні замовлення відсутні.\n");
    return;
  }

  printf("-------------------------------------\n");
  printf("1. Змінити тривалість оренди\n");
  printf("2. Скасувати замовлення\n");
  printf("3. Повернутися до меню\n");
  printf("-------------------------------------\n");
  printf("Оберіть дію: ");
  int action;
  scanf("%d", &action);
  switch (action) {
  case 1:
    changeMonths();
    break;
  case 2:
    cancelOrder();
    break;
  case 3:
    printf("Повернення до меню.\n");
    break;
  default:
    printf("Невірний вибір.\n");
    break;
  }
  printf("-------------------------------------\n");
}

void displayApartments() {
  printf("\n--------Доступні апартаменти---------\n");
  for (int i = 0; i < 10; i++) {
    if (strlen(apartments[i].type) == 0)
      continue;
    printf("Квартира %d\n", i + 1);
    printf("Тип: %s\n", apartments[i].type);
    printf("Адреса: %s\n", apartments[i].address);
    printf("Місто: %s\n", apartments[i].city);
    printf("Поверх: %d\n", apartments[i].floor);
    printf("Площа: %d\n", apartments[i].area);
    printf("Ціна за місяць: %.2f\n", apartments[i].price);
    printf("-------------------------------------\n");
  }
}

void rentApartment() {
  printf("\n-------Пошук і оренда квартири-------\n");
  printf("Введіть тип квартири(1-кімнатна, 2-кімнатна, 3-кімнатна): \n");
  char type[50];
  scanf("%s", type);

  printf("Введіть місто (Київ, Львів, Чернівці, Полтава): \n");
  char city[50];
  scanf("%s", city);

  int found = 0;
  for (int i = 0; i < 10; i++) {
    if (strcmp(type, apartments[i].type) == 0 &&
        strcmp(city, apartments[i].city) == 0) {
      printf("\nКвартира знайдена!\n");
      printf("Квартира %d\n", i + 1);
      printf("Тип: %s\n", apartments[i].type);
      printf("Адреса: %s\n", apartments[i].address);
      printf("Місто: %s\n", apartments[i].city);
      printf("Поверх: %d\n", apartments[i].floor);
      printf("Площа: %d\n", apartments[i].area);
      printf("Ціна за місяць: %.2f\n", apartments[i].price);

  int rent;
      printf("\nБажаєте орендувати цю квартиру? (1-так/0-ні): ");
      scanf("%d", &rent);
      if (rent == 1) {
        orders[orderCount] =
            (struct Order){.type = "",
                           .address = "",
                           .city = "",
                           .floor = apartments[i].floor,
                           .area = apartments[i].area,
                           .price = apartments[i].price,
                           .months = 0};
        strcpy(orders[orderCount].type, apartments[i].type);
        strcpy(orders[orderCount].address, apartments[i].address);
        strcpy(orders[orderCount].city, apartments[i].city);
        printf("Введіть тривалість оренди (місяців): ");
        scanf("%d", &orders[orderCount].months);
        printf("Замовлення успішно створено!\n");
        orderCount++;
      }
      found = 1;
      break;
    }
  }
if (!found) {
    printf("Квартира не знайдена.\n");
  }
  printf("-------------------------------------\n");
}

void displayMenu() {
  printf("\n----------------Меню-----------------\n");
  printf("1. Створити акаунт\n");
  printf("2. Увійти\n");
  printf("3. Переглянути інформацію про акаунт\n");
  printf("4. Переглянути поточні замовлення\n");
  printf("5. Відобразити всі доступні квартири\n");
  printf("6. Пошук і оренда квартири\n");
  printf("7. Вихід\n");
  printf("-------------------------------------\n");
}

int main() {
  
  strcpy(apartments[0].type, "1-кімнатна");
  strcpy(apartments[0].address, "Вул. Сумська, 45");
  strcpy(apartments[0].city, "Львів");
  apartments[0].floor = 3;
  apartments[0].area = 40;
  apartments[0].price = 5000;

  strcpy(apartments[1].type, "2-кімнатна");
  strcpy(apartments[1].address, "Вул. Мазепи, 15");
  strcpy(apartments[1].city, "Львів");
  apartments[1].floor = 5;
  apartments[1].area = 60;
  apartments[1].price = 8000;

  strcpy(apartments[2].type, "2-кімнатна");
  strcpy(apartments[2].address, "Вул. Грушевського, 10");
  strcpy(apartments[2].city, "Чернівці");
  apartments[2].floor = 2;
  apartments[2].area = 90;
  apartments[2].price = 12000;

  strcpy(apartments[3].type, "1-кімнатна");
  strcpy(apartments[3].address, "Вул. Шевченка, 20");
  strcpy(apartments[3].city, "Київ");
  apartments[3].floor = 1;
  apartments[3].area = 35;
  apartments[3].price = 4000;

  strcpy(apartments[4].type, "2-кімнатна");
  strcpy(apartments[4].address, "Вул. Франка, 30");
  strcpy(apartments[4].city, "Київ");
  apartments[4].floor = 4;
  apartments[4].area = 55;
  apartments[4].price = 7000;

  strcpy(apartments[5].type, "3-кімнатна");
  strcpy(apartments[5].address, "Вул. Бандери, 5");
  strcpy(apartments[5].city, "Київ");
  apartments[5].floor = 6;
  apartments[5].area = 85;
  apartments[5].price = 11000;

  strcpy(apartments[6].type, "1-кімнатна");
  strcpy(apartments[6].address, "Вул. Миру, 8");
  strcpy(apartments[6].city, "Полтава");
  apartments[6].floor = 2;
  apartments[6].area = 38;
  apartments[6].price = 4500;

  strcpy(apartments[7].type, "2-кімнатна");
  strcpy(apartments[7].address, "Вул. Лесі Українки, 12");
  strcpy(apartments[7].city, "Полтава");
  apartments[7].floor = 3;
  apartments[7].area = 65;
  apartments[7].price = 7500;

  strcpy(apartments[8].type, "3-кімнатна");
  strcpy(apartments[8].address, "Вул. Незалежності, 22");
  strcpy(apartments[8].city, "Чернівці");
  apartments[8].floor = 4;
  apartments[8].area = 95;
  apartments[8].price = 13000;

  strcpy(apartments[9].type, "1-кімнатна");
  strcpy(apartments[9].address, "Вул. Свободи, 18");
  strcpy(apartments[9].city, "Чернівці");
  apartments[9].floor = 5;
  apartments[9].area = 42;
  apartments[9].price = 5200;

  int choice;
  do {
    displayMenu();
    printf("\nОберіть пункт меню: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      createAccount();
      break;
    case 2:
      login();
      break;
    case 3:
      viewAccountInfo(newUser);
      break;
    case 4:
      viewOrders();
      break;
    case 5:
      displayApartments();
      break;
    case 6:
      rentApartment();
      break;
    case 7:
      printf("\nВихід з програми\n");
      break;
    default:
      printf("Невірний вибір. Спробуйте ще раз.\n");
      printf("-------------------------------------\n");
      break;
    }
  } while (choice != 7);

}
