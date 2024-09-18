#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QtCharts/QChartView>
#include<QtCharts/QLineSeries>
#include<QtCharts/QValueAxis>

#include <QtCharts/QValueAxis>

void MainWindow::setupGraphs()
{
    // pH graph data
    QLineSeries *phSeries = new QLineSeries();
    phSeries->append(177, 70.0);
    phSeries->append(197, 80.0);
    phSeries->append(217, 90.0);
    phSeries->append(237, 85.0);
    phSeries->append(257, 95.0);
    phSeries->append(277, 75.0);

    QChart *phChart = new QChart();
    phChart->legend()->hide();
    phChart->addSeries(phSeries);
    phChart->setTitle("pH");

    //  margins and layout for phChart
    phChart->setMargins(QMargins(5, 5, 5, 5));
    phChart->setTitleFont(QFont("Arial", 12));

    //  axes for pH chart
    QValueAxis *xAxisPh = new QValueAxis();
    xAxisPh->setRange(157, 278);
    xAxisPh->setTitleText("Entries");
    xAxisPh->setLabelsFont(QFont("Arial", 10));

    QValueAxis *yAxisPh = new QValueAxis();
    yAxisPh->setRange(0, 100);
    yAxisPh->setTitleText("Value");
    yAxisPh->setLabelsFont(QFont("Arial", 10));

    phChart->setAxisX(xAxisPh, phSeries);
    phChart->setAxisY(yAxisPh, phSeries);

    ui->phChartView->setChart(phChart);
    ui->phChartView->setRenderHint(QPainter::Antialiasing);
    ui->phChartView->setMinimumSize(300, 200);

    // PO4 graph data
    QLineSeries *po4Series = new QLineSeries();
    po4Series->append(178, 50.0);
    po4Series->append(198, 60.0);
    po4Series->append(218, 70.0);
    po4Series->append(238, 65.0);
    po4Series->append(258, 85.0);
    po4Series->append(278, 45.0);


    QChart *po4Chart = new QChart();
    po4Chart->legend()->hide();
    po4Chart->addSeries(po4Series);
    po4Chart->setTitle("PO4");

    //  margins and layout for po4Chart
    po4Chart->setMargins(QMargins(5, 5, 5, 5));
    po4Chart->setTitleFont(QFont("Arial", 12));

    //  axes for PO4 chart
    QValueAxis *xAxisPo4 = new QValueAxis();
    xAxisPo4->setRange(157, 278);
    xAxisPo4->setTitleText("Entries");
    xAxisPo4->setLabelsFont(QFont("Arial", 10));

    QValueAxis *yAxisPo4 = new QValueAxis();
    yAxisPo4->setRange(0, 100);
    yAxisPo4->setTitleText("Value");
    yAxisPo4->setLabelsFont(QFont("Arial", 10));

    po4Chart->setAxisX(xAxisPo4, po4Series);
    po4Chart->setAxisY(yAxisPo4, po4Series);

    ui->po4ChartView->setChart(po4Chart);
    ui->po4ChartView->setRenderHint(QPainter::Antialiasing);
    ui->po4ChartView->setMinimumSize(300, 200);

    // CL graph data
    QLineSeries *clSeries = new QLineSeries();
    clSeries->append(179, 40.0);
    clSeries->append(199, 50.0);
    clSeries->append(219, 55.0);
    clSeries->append(239, 65.0);
    clSeries->append(259, 75.0);
    clSeries->append(279, 35.0);

    QChart *clChart = new QChart();
    clChart->legend()->hide();
    clChart->addSeries(clSeries);
    clChart->setTitle("CL");

    // margins and layout for clChart
    clChart->setMargins(QMargins(5, 5, 5, 5));
    clChart->setTitleFont(QFont("Arial", 12));

    // axes for CL chart
    QValueAxis *xAxisCl = new QValueAxis();
    xAxisCl->setRange(157, 278);
    xAxisCl->setTitleText("Entries");
    xAxisCl->setLabelsFont(QFont("Arial", 10));

    QValueAxis *yAxisCl = new QValueAxis();
    yAxisCl->setRange(0, 100);
    yAxisCl->setTitleText("Value");
    yAxisCl->setLabelsFont(QFont("Arial", 10));

    clChart->setAxisX(xAxisCl, clSeries);
    clChart->setAxisY(yAxisCl, clSeries);

    ui->clChartView->setChart(clChart);
    ui->clChartView->setRenderHint(QPainter::Antialiasing);
    ui->clChartView->setMinimumSize(300, 200);
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //table contents
    ui->tableWidget->setRowCount(4);
    ui->tableWidget->setColumnCount(5);
    QStringList headers = {"Dummy","","Mixmass","2","GAL"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("Additives"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("Desired"));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem("Actual"));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("pH"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("9.75"));
    ui->tableWidget->setItem(1,3,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("PO4"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("160"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("ppm"));
    ui->tableWidget->setItem(2,3,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(2,4,new QTableWidgetItem("ppm"));
    ui->tableWidget->setItem(3,0,new QTableWidgetItem("CL"));
    ui->tableWidget->setItem(3,1,new QTableWidgetItem("2"));
    ui->tableWidget->setItem(3,2,new QTableWidgetItem("ppm"));
    ui->tableWidget->setItem(3,3,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(3,4,new QTableWidgetItem("ppm"));
    ui->tableWidget->resizeColumnsToContents();//adjusting the table
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    setupGraphs();
}

MainWindow::~MainWindow()
{

    delete ui;
}
