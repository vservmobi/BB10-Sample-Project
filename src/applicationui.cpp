#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>
#include <bb/cascades/controls/container.h>
#include <VservManager.hpp>
#include <bb/cascades/resources/actionitem.h>
#include <bb/cascades/resources/titlebar.h>
#include <bb/cascades/controls/actionbarplacement.h>
#include <bb/cascades/controls/page.h>
#include <bb/cascades/layouts/stacklayout.h>
#include <bb/cascades/layouts/stacklayoutproperties.h>
#include <bb/cascades/layouts/absolutelayout.h>
#include <bb/cascades/layouts/absolutelayoutproperties.h>
#include <bb/cascades/layouts/docklayout.h>

using namespace bb::cascades;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
        QObject(app)
{
	page = new Page;
	TitleBar *titleBar = TitleBar::create(TitleBarKind::Default);
	titleBar->setTitle("VservBB10SampleApp");
	page->setTitleBar(titleBar);
	rootContainer = new Container();
	StackLayout *myStackLayout = new StackLayout();
	rootContainer->setLayout(myStackLayout);

	// Create the first child container
	Container *childContainer = Container::create();

	displayAdButton = new Button();
	displayAdButton->setText("Display Interstitial <DisplayAd()>  >");
	// Connect the button's clicked() signal to a slot function.
	connect(displayAdButton, SIGNAL(clicked()), this, SLOT(onDisplayAdClicked()));

	renderAdButton = new Button();
	renderAdButton->setText("Display Banner <RenderAd()>  >");
	// Connect the button's clicked() signal to a slot function.
	connect(renderAdButton, SIGNAL(clicked()), this, SLOT(onRenderAdClicked()));

	/*Adding Buttons in child Container*/
	childContainer->add(displayAdButton);
	childContainer->add(renderAdButton);
	/*Adding chidContainer into rootContainer*/
	rootContainer->add(childContainer);

	/*add webView container in rootContainer for display banner Ad*/
	webViewContainer = Container::create();
	webViewContainer->setTopMargin(20);
	webViewContainer->setBottomMargin(20);
	rootContainer->add(webViewContainer);

	/*add container in page*/
	page->setContent(rootContainer);
	/*adding page in app*/
	app->setScene(page);

	/*Initialization of VservManager class getting instance of VservManager Class*/
	vManager = VservManager::GetInstance();

	/*Setting all required details in VservManager*/
	vManager->setAge("26"); // set your Age
	vManager->setBirthDate("08-06-1987"); // set your Date-Of-Birth
	vManager->setCity("Mumbai"); // set your city
	vManager->setCountry("India"); // set your country
	vManager->setEmail("abc@gmail.com"); // set your email if
	vManager->setGender("Male"); // set your gender
	//vManager->setPartnerId("You Partner Id"); // set your partner id
	vManager->setShowAt("in"); // set required postition of your Ad (Ex:- start/in/)
	//vManager->setStoreFrontId("Your StoreFront Id"); // set your storeFrontId
	vManager->setConnectionTimeOut(20); // set your network connection timeout in seconds default timeout value is 20 secs
}

/* onDisplayAdClicked is a slots function called when DisplayAd button clicked
 * inside it calling DisplayAd function of VservManager class passing zoneId
 * (get ZoneId from Vserv) as a string parameter
 *
 * */

void ApplicationUI::onDisplayAdClicked(){
	/*Call to Display Fullscreen Ad*/
	vManager->DisplayAd("8063");
}

/* onRenderAdClicked is a slots function called when RenderAd button clicked
 * inside it calling RenderAd function of VservManager class ,passing zoneId (get ZoneId from Vserv)
 *  as a String and container object as a parameter for adding banner Ad on it
 * */

void ApplicationUI::onRenderAdClicked(){
	if(webViewContainer != NULL) {
		webViewContainer->removeAll();
	}

	vManager->setShowAt("in");
	/*Call to display Banner Ad on your App Screen*/
	vManager->RenderAd("20846", webViewContainer);
}
