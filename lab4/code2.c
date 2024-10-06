#include <stdio.h>
#include <stdlib.h>


float celsius_to_fahrenheit (float celsius)
{
	return ((9.0/5.0) * celsius + 32);
}

float fahrenheit_to_celsius (float fahrenheit)
{
	return (5.0/9.0)*(fahrenheit - 32);
}

float celsius_to_kelvin (float celsius)
{
	return celsius + 273.15;
}

float kelvin_to_celsius (float kelvin)
{
	return kelvin - 273.15;
}

float fahrenheit_to_kelvin (float fahrenheit)
{
	return ((fahrenheit - 32)/1.8) + 273.15;
}

float kelvin_to_fahrenheit (float kelvin)
{
	return 1.8 * (kelvin - 273.15) + 32;
}

void categorize_temperature(float celsius)
{
	if (celsius < 0)
	{
		printf("Temperature category: Freezing");
		printf("\nWeather Advisory: Stay indoors");
	} else if (celsius < 10) {
		printf("Temperature category: Cold");
		printf("\nWeather Advisory: Wear insulating layers");
	} else if (celsius < 25) {
		printf("Temperature category: Comfortable");
		printf("\nWeather Advisory: Enjoy the weather!");
	} else if (celsius < 35) {
		printf("Temperature category: Hot");
		printf("\nWeather Advisory: Wear SPF and drink water.");
	} else if (celsius > 35) {
		printf("Temperature category: Extreme Heat");
		printf("\nWeather Advisory: Stay indoors");
	}
}

int main()
{

	char input[10];  // Buffer to hold the input (both for temp and 'Q')
    float temp;
    int scale, convert;

	while(1){
		printf("\nEnter the temperature (Q to quit): ");
		scanf("%s", input);

		// error checking logic
		if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }

        if (input[0] != '-' && (input[0] < '0' || input[0] > '9')) {
            printf("Invalid input. Please try again.");
            continue;
        }

        // Convert the input string to a float (temperature)
        temp = atof(input);

        // user input
		printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
		scanf("%d", &scale);
        if (scale != 1 && scale != 2 && scale != 3) {
            printf("Invalid input. Please try again.");
            continue;
        }

		printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
		scanf("%d", &convert);
        if (convert != 1 && convert != 2 && convert != 3) {
            printf("Invalid input. Please try again.");
            continue;
        }

		if (temp < 0 && scale == 3){
			printf("Temperatures on the Kelvin scale cannot be negative.");
			continue;
		}

		//Temperature scale and conversion logic
		if (scale == 1 && convert == 2) {
            printf("Temperature in Fahrenheit: %.2f\n", celsius_to_fahrenheit(temp));
            categorize_temperature(temp);
        } else if (scale == 1 && convert == 3) {
            printf("Temperature in Kelvin: %.2f\n", celsius_to_kelvin(temp));
            categorize_temperature(temp);
		} else if (scale == 2 && convert == 1) {
            printf("Temperature in Celsius: %.2f\n", fahrenheit_to_celsius(temp));
            categorize_temperature(fahrenheit_to_celsius(temp));
        } else if (scale == 2 && convert == 3) {
            printf("Temperature in Kelvin: %.2f\n", fahrenheit_to_kelvin(temp));
            categorize_temperature(fahrenheit_to_celsius(temp));
        } else if (scale == 3 && convert == 1) {
            printf("Temperature in Celsius: %.2f\n", kelvin_to_celsius(temp));
            categorize_temperature(kelvin_to_celsius(temp));
        } else if (scale == 3 && convert == 2) {
            printf("Temperature in Fahrenheit: %.2f\n", kelvin_to_fahrenheit(temp));
            categorize_temperature(kelvin_to_celsius(temp));
        } else if (scale == convert && scale == 1) {
            printf("Temperature in Celsius: %.2f\n", temp);
            categorize_temperature(temp);
        } else if (scale == convert && scale == 2) {
            printf("Temperature in Fahrenheit: %.2f\n", temp);
            categorize_temperature(fahrenheit_to_celsius(temp));
        } else if (scale == convert && scale == 3) {
            printf("Temperature in Kelvin: %.2f\n", temp);
            categorize_temperature(kelvin_to_celsius(temp));
        } else {
            printf("Invalid input. Please try again.");
        }
	}
}