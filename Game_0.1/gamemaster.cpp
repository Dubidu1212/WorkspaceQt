#include "gamemaster.h"

void GameMaster::tilecreator(){
    imageloader il;
    QStringList sources;
    for(int x = 0; x < mp.tilesets.length();x++){
        sources.append(mp.tilesets[x].source);
    }

    QList <QImage> images;
   images = il.Loadtilesets(mp.tilesets.length(),sources);
    for(int x = 0; x < mp.tilesets.length(); x++){//jedes tileset durchläuft diesen prozess
        QImage TempImage = images.at(x); //sind source
        int varY = 0;
        int tileheight = mp.tilesets.at(x).tileheight;


        int rows = mp.tilesets.at(x).tilecount /  mp.tilesets.at(x).columns;

        for(int z = 0; z < rows; z++){

            int varX = 0;
            for(int y = 0; y < mp.tilesets.at(x).columns ;y++){

                gid.append(TempImage.copy(varX,varY,tileheight,tileheight));
                //std::cout << tileheight << std::endl;
                varX += tileheight;
            }
            varY += tileheight;

        }





    }
}

void GameMaster::spawn(){
    if(Enemys < 2){
        int d = qrand() % spawner.length();
        Enemy * en = new Enemy(&UpdaterEnemy,UpdaterEnemy.length());

        UpdaterEnemy.append(en);
        pl->scene()->addItem(en);
        en->setPos(spawner.at(d-1)->pos());
        Enemys++;
    }



}
void GameMaster::control(){
    for(int x = 0; x < UpdaterEnemy.length() ;x++){
        UpdaterEnemy.at(x)->move();
    }
}

void GameMaster::update(){

    if(time < 0){

        time = qrand() % 10;
        spawn();
    }
    else{
        time--;
    }
    control();




}
GameMaster::GameMaster(QApplication * app){

    int hoehe = 500; //!blidschirmgrösse

    QFontDatabase::addApplicationFont(":/fonts/ENDOR___.ttf");

    dfont.setFamily("ENDOR");
    app->setFont(dfont);




    QFile *file = new QFile(":/xml/Real1.tmx");


    QXmlSimpleReader xmlReader;
    QXmlInputSource *source = new QXmlInputSource(file);



    Handler *handler = new Handler;
    xmlReader.setContentHandler(handler);
    xmlReader.setErrorHandler(handler);



    bool ok = xmlReader.parse(source);

    if (!ok)
        std::cout << "Parsing failed." << std::endl;

    else {
        QStringList names = handler->names();
        QStringList attributes = handler->attributes();
        QStringList attributeName = handler->attributeName();
        QList<int> indentations = handler->indentations();
        QList<int> anzahl = handler->anzahl();

        //liste mit allen tiles erstellen ( gid )
       this->tilecreator();

    }
    controls.down = false;
    controls.up = false;
    controls.left = false;
    controls.right = false;


    pl = new Player(QRect(0,0,64,64));

    //pl->setPixmap(QPixmap().fromImage( QImage(":/sprites/Arm_front.png").copy(0,0,64,64)));

    pl->setVisible(true);

    updater * updat = new updater(10);
    pl->setPos(50,50);
    pl->setScale(1);

    MainWindow * w = new MainWindow();
    updat->Dvi = w->View();
    w->show();









    std::cout << "Beendet"  <<std::endl;

    QTimer * timer = new QTimer(this);//hier
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
            timer->start(100);

}
