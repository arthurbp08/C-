#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    // Loop para acender as LEDs em sequência
    for(int i = 0; i < 5; i++) {
        cout << "Acendendo LED " << i + 1 << endl;
        // Simulação de acender a LED (substitua com o código real)
        usleep(500000); // Aguarda meio segundo
    }

    // Loop para piscar as LEDs
    while(true) {
        for(int i = 0; i < 5; i++) {
            cout << "Piscando LED " << i + 1 << endl;
            // Simulação de piscar a LED (substitua com o código real)
            usleep(250000); // Aguarda um quarto de segundo
        }
        // Aguarda um segundo antes de piscar novamente
        sleep(1);
    }

    return 0;
}
