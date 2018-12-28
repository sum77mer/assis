#pragma once
#include<QString>
#include<QFont>
#include<QColor>

//Font
const QFont enNormalFont = QFont("Arial", 10, QFont::Normal);
const QFont chNormalFont = QFont("Î¢ÈíÑÅºÚ", 10, QFont::Normal);

const QFont enTitleFont = QFont("Arial", 12, QFont::Normal);
const QFont chTitleFont = QFont("Î¢ÈíÑÅºÚ", 15, QFont::Normal);

const QFont enTitleFontL = QFont("Arial", 15, QFont::Bold);
const QFont chTitleFontL = QFont("Î¢ÈíÑÅºÚ", 17, QFont::Normal);

const QString bottomFrameColor = QString("QFrame{background-color:rgb(245,245,245);border-top-color:rgb(200,200,200);border-width:1px;border-color:rgb(200,200,200);border-style:solid}");

//Style
const QString titleStyle = "QLabel{border-width:0px 0px 1px 0px;border-style:solid;border-color:rgb(200,200,200);padding-bottom:3px}";