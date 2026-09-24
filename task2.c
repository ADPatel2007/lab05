#include <stdio.h>
#include <ctype.h>

double to_celsius(double temp, char scale) {
    if (scale == 'C') return temp;
    if (scale == 'F') return (temp - 32.0) * (5.0 / 9.0);
    if (scale == 'K') return temp - 273.15;
    return 0.0;
}

double from_celsius(double temp_c, char target) {
    if (target == 'C') return temp_c;
    if (target == 'F') return (temp_c * (9.0 / 5.0)) + 32.0;
    if (target == 'K') return temp_c + 273.15;
    return 0.0;
}

void print_category_and_advisory(double temp_c) {
    if (temp_c < 0.0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy coat, gloves, and a warm hat!\n");
    } else if (temp_c < 10.0) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket and dress in layers.\n");
    } else if (temp_c < 25.0) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: The weather is pleasant. Enjoy your day outside!\n");
    } else if (temp_c < 35.0) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and keep hydrated!\n");
    }
}

int is_valid_scale(char s) {
    return (s == 'C' || s == 'F' || s == 'K');
}

int main(void) {
    double temp;
    char from_scale, to_scale;

    printf("Enter the temperature value: ");
    if (scanf("%lf", &temp) != 1) {
        printf("Error: Invalid numerical temperature input.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &from_scale);
    from_scale = toupper(from_scale);

    if (!is_valid_scale(from_scale)) {
        printf("Error: Invalid scale '%c'. Please use C, F, or K.\n", from_scale);
        return 1;
    }

    if (from_scale == 'K' && temp < 0.0) {
        printf("Error: Temperature in Kelvin cannot be negative.\n");
        return 1;
    }

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &to_scale);
    to_scale = toupper(to_scale);

    if (!is_valid_scale(to_scale)) {
        printf("Error: Invalid target scale '%c'. Please use C, F, or K.\n", to_scale);
        return 1;
    }

    double temp_c = to_celsius(temp, from_scale);
    double converted = from_celsius(temp_c, to_scale);

    if (to_scale == 'K' && converted < 0.0) {
        printf("Error: Converted temperature results in an invalid Kelvin value below absolute zero.\n");
        return 1;
    }

    printf("Converted temperature: %.2f %c\n", converted, to_scale);
    print_category_and_advisory(temp_c);

    return 0;
}
