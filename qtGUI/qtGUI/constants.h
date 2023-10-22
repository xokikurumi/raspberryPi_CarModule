#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QMainWindow>
#include<iostream>

#define ODO_QUERY "SELECT km FROM meter WHERE id = 2001;"
#define TRIP_A_QUERY "SELECT km FROM meter WHERE id = 1001;"
#define TRIP_B_QUERY "SELECT km FROM meter WHERE id = 1002;"
#define TEMP_QUERY "SELECT value FROM status WHERE id = 1001;"
#define HUM_QUERY "SELECT value FROM status WHERE id = 1002;"
#define WDGT_QUERY "SELECT value FROM status WHERE id = 1003;"
#define STATUS_LEVEL_QUERY "SELECT value FROM status WHERE id = 1004;"


static QString ENABLED_BTN ={
  "color: rgb(255, 255, 255);\
    background-color: GREEN;\
   border: solid 1px green;"
};

static QString DISABLED_BTN ={
  "color: rgb(255, 0, 0);\
    background-color: rgb(50, 0, 0);\
    border: solid 1-x #FFFFFF;"
};

static QString STATUS_LEVEL_1 ={
  "color: #FFFFFF;"
};

static QString STATUS_LEVEL_2 ={
  "color: #87CEED;"
};

static QString STATUS_LEVEL_3 ={
  "color: #FFFF00;"
};


static QString STATUS_LEVEL_4 ={
  "color: #FFA500;"
};

static QString STATUS_LEVEL_5 ={
  "color: #FF0000;"
};



// Labels
static QString UI_TRIP_A_TITLE_LABEL = {"Trip A"};
static QString UI_TRIP_B_TITLE_LABEL = {"Trip B"};

// SQLite Settings.
#define DB_TYPE = "QSQLITE"
#define DB_PATH = "/tmp/wk/carModule.sqlite3"
#define QUERY_SELECT_STATUS = "SELECT "

#endif // CONSTANTS_H
