#include <QtGui>
#include <QTableView>
#include <QSqlQueryModel>
#include "editablesqlmodel.h"
#include <QtSql>
#include <QSqlDatabase>

 void initializeModel(QSqlQueryModel *model)
 {

     model->setQuery("select * from SurveyPerson");
 }

 QTableView* createView(QSqlQueryModel *model)
 {
     QTableView *view = new QTableView;
     view->setModel(model);

     view->show();

     return view;
 }

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);

     EditableSqlModel *editableModel = new EditableSqlModel;
     initializeModel(editableModel);

     createView(editableModel);

     return app.exec();
 }
