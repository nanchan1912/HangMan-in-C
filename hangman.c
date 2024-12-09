#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//animal hangman.c
char* array_words[200] = {
"dog", "cat", "horse", "cow", "pig", "chicken", "sheep", "goat", "duck", "goose", 
"turkey", "rabbit", "mouse", "rat", "hamster", "pig", "goldfish", "parrot", 
"pigeon", "sparrow", "robin", "jay", "cardinal", "crow", "raven", "seagull", 
"swan", "flamingo", "peacock", "eagle", "hawk", "falcon", "owl", "penguin", 
"ostrich", "kangaroo", "koala", "bear", "panda", "elephant", "tiger", "lion", 
"cheetah", "leopard", "giraffe", "zebra", "hippopotamus", "rhinoceros", "deer", 
"moose", "elk", "bison", "buffalo", "fox", "wolf", "coyote", "raccoon", "skunk", 
"opossum", "squirrel", "chipmunk", "beaver", "otter", "seal", "sea lion", "walrus", 
"dolphin", "whale", "shark", "octopus", "squid", "crab", "lobster", "shrimp", "clam", 
"oyster", "snail", "slug", "earthworm", "ant", "bee", "wasp", "hornet", "butterfly", 
"moth", "beetle", "ladybug", "grasshopper", "cricket", "cockroach", "spider", 
"scorpion", "frog", "toad", "salamander", "lizard", "snake", "turtle", "tortoise", 
"crocodile", "alligator", "bat", "monkey", "chimpanzee", "gorilla", "orangutan", 
"baboon", "lemur", "sloth", "armadillo", "porcupine", "hedgehog", "ferret", "weasel", 
"badger", "mongoose", "hyena", "meerkat", "donkey", "mule", "llama", "alpaca", 
"camel", "flamingo", "pelican", "heron", "stork", "turkey", "woodpecker", "finch", 
"canary", "swallow", "dove", "owl", "magpie", "kookaburra", "emu", "cassowary", 
"quail", "pheasant", "grouse", "partridge", "puffin", "kingfisher", "kestrel", 
"vulture", "chameleon", "gecko", "iguana", "newt", "hummingbird", "bison", "yak", 
"parakeet", "finch", "starling", "lynx", "bobcat", "caracal", "ocelot", "manatee", 
"narwhal", "platypus", "echidna", "koala", "wallaby", "cockroach"
};

char* word_chooser(){
    char* word;
    srand(time(NULL));
    int n = rand()%200;
    return array_words[n];
}

void update_array(char guess, char* array, char* word, int* chances){
    int length = strlen(word);
    int count = 0;
    for(int i = 0;i<length;i++){
        if(guess == word[i]){
            array[i] = guess;
            printf("guess correct! chances left = %d\n", *chances);
            count = 1;
        }
    }

    if(count == 0){
    (*chances)--;
    printf("guess wrong! chances left = %d\n", *chances);
    }
}

void setup_array(char* array){
    int length = strlen(array);
    for(int i =0;i<length;i++){
        array[i] = '_';
    }
}

char guy[100];

void guy_maker(int chances){
    if(chances == 6){
        strcpy(guy, " O\n/|\\\n/ \\\n");
    }
    if(chances == 5){
        strcpy(guy, " O\n/|\\\n/ \n");
    }
    if(chances == 4){
        strcpy(guy, " O\n/|\\\n");
    }
    if(chances == 3){
        strcpy(guy, " O\n/|\n");
    }
    if(chances == 2){
        strcpy(guy, " O\n |\n");
    }
    if(chances == 1){
        strcpy(guy, " O\n");
    }
    if(chances == 0){
        strcpy(guy, "you lost lmfao\n");
    }
    return;
}

int main(){
    char* word = word_chooser();
    char output[100];
    strcpy(output, word);
    setup_array(output);
    int chances = 6;
    char guess;
    printf("WELCOME TO HANGMAN\n");
    printf("    O\n");
    printf("   /|\\\n");
    printf("   / \\\n");
    printf("make your first guess:\n");

    
    while(chances != 0){
        scanf(" %c", &guess);
        update_array(guess, output, word, &chances);
        guy_maker(chances);
        printf("%s\n", output);
        printf("%s\n", guy);
        if(strcmp(output, word)==0){
            printf("YOU GUESSED IT RIGHT!\n");
            return 0;
        }
    }
    printf("EH EH EH YOU LOST :(\n");
    printf("the word was %s\n", word);
}
