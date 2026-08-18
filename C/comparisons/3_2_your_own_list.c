#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*lists*/



int main() {

    char *friends_names[] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    char *activities[] = {"drive", "sell", "buy", "repair", "race"};
    char *conectives[] = {"my", "a", "new", "the", "with", "to go", "to"};
    char *cities[] = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix"};
    char *cars[] = {"Toyota", "Honda", "Ford", "Chevrolet", "Nissan"};
    char *firstPart = "I would like to ";

    printf("%s%s %s %s in %s.\n", firstPart, activities[0], conectives[0], cars[0], cities[0]);
    printf("%s%s %s %s in %s.\n", firstPart, activities[1], conectives[1], cars[1], cities[1]);
    printf("%s%s %s %s in %s.\n", firstPart, activities[2], conectives[2], cars[2], cities[2]);
    printf("%s%s %s %s in %s.\n", firstPart, activities[3], conectives[3], cars[3], cities[3]);
    printf("%s%s %s %s in %s.\n", firstPart, activities[4], conectives[4], cars[4], cities[4]);
    
    return 0;
}