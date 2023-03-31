#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void dessin()
{
	printf("                __                             __           __  __                  _      _                \n");
	printf(" _      _____  / /________  ____ ___  ___     / /_____     / /_/ /_  ___     ____ _(_)____/ (_)___  ___  _____\n");
	printf("| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\   / __/ __ \\/ _ \\   / __ `/ / ___/ / / __ \\/ _ \\/ ___/\n");
	printf("| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /_/ / / /  __/  / /_/ / / /  / / / / / /  __(__ ) \n");
	printf("|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/   \\__/\\____/   \\__/_/ /_/\\___/   \\__,_/_/_/  /_/_/_/ /_/\\___/____/  \n");
}

void menu()
{
	printf("\n");
	printf("              +------------------------------------------------------------------------------+\n");
	printf("              |                                   MENU                                       |\n");
	printf("              +------------------------------------------------------------------------------+\n");
	printf("              | 1. Remplir la liste des avions                                               |\n");
	printf("              | 2. Verifier si un avion est dans l'aeroport                                  |\n");
	printf("              | 3. Supprimer les avions anciens et en maintenance                            |\n");
	printf("              | 4. Trier la liste des avions par ordre croissant des capacites               |\n");
	printf("              | 5. Afficher le nombre d'avions decolles et atterris                          |\n");
	printf("              | 6. Afficher les avions avec le maximum de vols et ages de moins de 10 ans    |\n");
	printf("              | 7. Afficher les avions avec le minimum de vols et ages de moins de 10 ans    |\n");
	printf("              | 8. Scinder la liste en 3 : une pour les avions decolles, une pour les avions |\n");
	printf("              |    atterris et une pour les avions en maintenance                            |\n");
	printf("              | 0. Quitter le menu                                                           |\n");
	printf("              +------------------------------------------------------------------------------+\n");
	printf("              Rq: le programme ne prend que la partie entiere lors de l'entree des valeurs flottantes\n");
}


#endif	// MENU_H_INCLUDED
