#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <VservManager.hpp>
#include <bb/cascades/controls/textfield.h>
#include <bb/cascades/controls/button.h>
#include <bb/cascades/controls/page.h>

namespace bb
{
    namespace cascades
    {
        class Application;
        class LocaleHandler;
    }
}

class QTranslator;

/*!
 * @brief Application object
 *
 *
 */

class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() { }
    public slots:
    	void onDisplayAdClicked();
    	void onRenderAdClicked();
    private:
    	Page* page;
    	Container* rootContainer;
    	Container* webViewContainer; // conatiner for display banner Ad
    	VservManager* vManager; // VservManager class object
    	Button* displayAdButton; // button object for display fullscreen Ad
    	Button* renderAdButton; // button object for display banner Ad on App
};

#endif /* ApplicationUI_HPP_ */
