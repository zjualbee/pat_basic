#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov 26 15:20:57 2020

@author: caoting
"""

import sys
from PyQt5.QtWidgets import QApplication, QMainWindow
from functools import partial

import conversion

def click_success():
    print('hahha, we have finally suceeded!')

def convert(ui):
    input = ui.lineEdit.text()
    result = float(input)*6.7
    ui.lineEdit_2.setText(str(result))

if __name__ == '__main__':
    app = QApplication(sys.argv)
    MainWindow = QMainWindow()
    ui = conversion.Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    ui.pushButton.clicked.connect(partial(convert,ui))
    sys.exit(app.exec_())