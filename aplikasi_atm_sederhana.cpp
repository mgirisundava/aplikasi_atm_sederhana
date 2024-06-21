#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void login(char names[][50], char banks[][50], int pin[], int *currentUser)
{
    int enteredPin;
    char name[50];
    int isLoginSuccess = 0;

    do
    {
        system("clear");
        printf("Masukkan PIN (6 Digit): ");
        scanf("%d", &enteredPin);
        if (enteredPin >= 100000 && enteredPin <= 999999)
        {
            int isPinCorrect = 0;
            for (int i = 0; i < 3; i++)
            {
                if (enteredPin == pin[i])
                {
                    isPinCorrect = 1;
                    if (strcmp(banks[i], "BCA") == 0)
                    {
                        strcpy(name, names[i]);
                        *currentUser = i;
                        system("clear");
                        printf("Selamat datang %s\n", name);
                        isLoginSuccess = 1;
                        break;
                    }
                    else
                    {
                        *currentUser = -1;
                        system("clear");
                        printf("Mohon maaf, hanya pengguna BCA yang dapat menggunakan ATM ini.");
                        printf("\n\nKetuk apapun untuk kembali.");
                        getchar();
                        getchar();
                        system("clear");
                    }
                }
            }
            if (!isPinCorrect)
            {
                system("clear");
                printf("PIN salah!\n\n");
                printf("nKetuk apapun untuk kembali.");
                getchar();
                getchar();
                system("clear");
            }
        }
        else
        {
            system("clear");
            printf("PIN harus 6 digit!\n\n");
            printf("Ketuk apapun untuk kembali.");
            getchar();
            getchar();
            system("clear");
        }
    } while (!isLoginSuccess);
}

void checkBalance(char names[][50], double balances[], int currentUser)
{
    system("clear");
    printf("Saldo Anda: Rp. %.2f\n\n", balances[currentUser]);
    printf("Ketuk apapun untuk kembali.");
    getchar();
    getchar();
    system("clear");
}

void deposit(double balances[], int currentUser)
{
    double amount;

    system("clear");
    printf("Masukkan jumlah setoran: Rp. ");
    scanf("%lf", &amount);
    balances[currentUser] += amount;
    system("clear");
    printf("Setoran berhasil! Saldo Anda sekarang: Rp. %.2f\n\n", balances[currentUser]);
    printf("Ketuk apapun untuk kembali.");
    getchar();
    getchar();
    system("clear");
}

void changePin(int pin[], int currentUser)
{
    int newPin;

    system("clear");
    printf("Masukkan PIN baru (6 Digit): ");
    scanf("%d", &newPin);
    if (newPin >= 100000 && newPin <= 999999)
    {
        system("clear");
        pin[currentUser] = newPin;
        printf("PIN berhasil diubah!\n\n");
        printf("Ketuk apapun untuk kembali.");
        getchar();
        getchar();
        system("clear");
    }
    else
    {
        system("clear");
        printf("PIN harus 6 digit!\n\n");
        printf("Ketuk apapun untuk kembali.");
        getchar();
        getchar();
        system("clear");
    }
}

void withdraw(double balances[], int currentUser)
{
    int choice;
    double amount = 0;
    bool isExit = false;

    while (isExit == false)
    {
        system("clear");
        printf("Pilih nominal:\n\n");
        printf("1. 50.000\n");
        printf("2. 100.000\n");
        printf("3. 200.000\n");
        printf("4. 500.000\n");
        printf("5. Masukkan Nominal\n\n");
        printf("6. Batal\n\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            balances[currentUser] -= 50000;

            system("clear");
            printf("Tarik tunai berhasil! Saldo Anda sekarang: Rp. %.2f\n\n", balances[currentUser]);
            printf("Ketuk apapun untuk kembali.");
            getchar();
            getchar();
            system("clear");
            isExit = true;
        }
        else if (choice == 2)
        {
            balances[currentUser] -= 100000;

            system("clear");
            printf("Tarik tunai berhasil! Saldo Anda sekarang: Rp. %.2f\n\n", balances[currentUser]);
            printf("Ketuk apapun untuk kembali.");
            getchar();
            getchar();
            system("clear");
            isExit = true;
        }
        else if (choice == 3)
        {
            balances[currentUser] -= 200000;

            system("clear");
            printf("Tarik tunai berhasil! Saldo Anda sekarang: Rp. %.2f\n\n", balances[currentUser]);
            printf("Ketuk apapun untuk kembali.");
            getchar();
            getchar();
            system("clear");
            isExit = true;
        }
        else if (choice == 4)
        {
            balances[currentUser] -= 500000;

            system("clear");
            printf("Tarik tunai berhasil! Saldo Anda sekarang: Rp. %.2f\n\n", balances[currentUser]);
            printf("Ketuk apapun untuk kembali.");
            getchar();
            getchar();
            system("clear");
            isExit = true;
        }
        else if (choice == 5)
        {
            system("clear");
            printf("Masukkan jumlah tarik tunai: Rp. ");
            scanf("%lf", &amount);
            if (amount <= 0)
            {
                system("clear");
                printf("Jumlah tarik tunai harus lebih dari nol.\n\n");
                printf("Ketuk apapun untuk kembali.");
                getchar();
                getchar();
                system("clear");
                isExit = true;
            }
            else if (amount > balances[currentUser])
            {
                system("clear");
                printf("Mohon maaf, saldo Anda tidak cukup.\n\n");
                printf("Ketuk apapun untuk kembali.");
                getchar();
                getchar();
                system("clear");
                isExit = true;
            }
            else
            {
                balances[currentUser] -= amount;
                system("clear");
                printf("Tarik tunai berhasil! Saldo Anda sekarang: Rp. %.2f\n\n", balances[currentUser]);
                printf("Ketuk apapun untuk kembali.");
                getchar();
                getchar();
                system("clear");
                isExit = true;
            }
        }
        else if (choice == 6)
        {
            system("clear");
            isExit = true;
            return;
        }
        else
        {
            system("clear");
            printf("Input tidak valid!\n\n");
            printf("Ketuk apapun untuk kembali.");
            getchar();
            getchar();
            system("clear");
        }
    }
}

void switchAccount(char names[][50], char banks[][50], int pin[], int *currentUser)
{
    *currentUser = -1;
    login(names, banks, pin, currentUser);
}

int main()
{

    char names[3][50] = {"Giri", "Riki", "Hilmi"};
    char banks[3][50] = {"BCA", "BRI", "BCA"};
    double balances[3] = {3500000, 2500000, 10000000};
    int pin[3] = {111111, 222222, 333333};
    int currentUser = -1;
    int choice;
    bool isExit = false;

    login(names, banks, pin, &currentUser);

    if (currentUser == -1)
    {
        printf("Program diberhentikan.\n");
        return 0;
    }

    while (isExit == false)
    {
        printf("Pilih yang Anda ingin lakukan:\n\n");
        printf("1. Cek Saldo\n");
        printf("2. Tarik Tunai\n");
        printf("3. Setor Tunai\n");
        printf("4. Transfer\n");
        printf("5. Ubah PIN\n");
        printf("6. Keluar\n\n");
        printf("7. Hentikan Program\n");
        printf("\nPilih opsi: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            checkBalance(names, balances, currentUser);
        }
        else if (choice == 2)
        {
            withdraw(balances, currentUser);
        }
        else if (choice == 3)
        {
            deposit(balances, currentUser);
        }
        else if (choice == 4)
        {
            // TRANSFER
        }
        else if (choice == 5)
        {
            changePin(pin, currentUser);
        }
        else if (choice == 6)
        {
            switchAccount(names, banks, pin, &currentUser);
            if (currentUser == -1)
            {
                printf("Program diberhentikan.\n");
                return 0;
            }
        }
        else if (choice == 7)
        {
            system("clear");
            printf("Terima kasih telah menggunakan ATM ini!\n\n");
            isExit = true;
        }
        else
        {
            system("clear");
            printf("Input tidak valid!\n\n");
            printf("Ketuk apapun untuk kembali.");
            getchar();
            getchar();
            system("clear");
        }
    }

    return 0;
}
