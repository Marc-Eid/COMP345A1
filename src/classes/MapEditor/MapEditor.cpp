//
// Created by Oliver Hassan on 2024-03-08.
//

#include "MapEditor.h"

using namespace std;

void MapEditor::runMapEditor(){
    cout << "What size map would you like to create?" << endl;
    cout << "Map width = ";
    int mapWidth, mapHeight;
    cin >> mapWidth;
    cout << "Map height = ";
    cin >> mapHeight;
    cout << mapWidth << "x" << mapHeight << endl;

    Map map = Map(mapWidth, mapHeight);

    map.Place(0,3,'S');
    map.Place(7,0,'E');
    map.printMap();

    map.isValid();
}