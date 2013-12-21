#pragma once

#include <QMainWindow>
#include "languagedb.h"

namespace Ui {
class MainWindow;
}

class QAction;
class QToolButton;
class QCloseEvent;
class QClipboard;
class QSettings;
class QTranslator;
class QxtGlobalShortcut;
class TextToolbar;
class Settings;
class TrayIcon;
class Translate;
class Popup;
class LanguageDB;
class Pronounce;

#define DEFAULT_SOURCE_LANGUAGE "English"
#define DEFAULT_RESULT_LANGUAGE "Russian"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void about();
    void quit();
    void swap();
    void translate();

    void changeVisibility();
    void updateSettings();
    void pronounceSourceText();
    void pronounceResultText();
private:
    void closeEvent(QCloseEvent *);
    void changeEvent(QEvent *e);
    bool applicationInFocus();

    QString sourceLanguage() const;
    QString resultLanguage() const;
    QString sourceText() const;
    QString resultText() const;

    QString last_locale;

    QAction *action_settings;
    QAction *action_about;
    QAction *action_exit;
    QToolButton *menu_button;
    QMenu *menu_root;
    QClipboard *clipboard;
    QSettings *settings;
    QTranslator *ui_translator;
    QxtGlobalShortcut *translate_shortcut;

    TextToolbar *toolbar_source_text;
    TextToolbar *toolbar_result_text;
    Settings *settings_dialog;
    TrayIcon *tray_icon;
    Translate *translate_engine;
    Pronounce *pronounce_engine;
    Popup *popup;
    LanguageDB *langdb;

    Ui::MainWindow *ui;
};
