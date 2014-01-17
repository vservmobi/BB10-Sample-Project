/*
 * VservManager.hpp
 *
 *  Created on: 22-Aug-2013
 *      Author: Gayatri Mishra
 */

#ifndef VSERVMANAGER_HPP_
#define VSERVMANAGER_HPP_

#include <qt4/QtCore/qstring.h>
#include <bb/cascades/controls/container.h>

using namespace bb::cascades;
class VservManager {
	public:
	   static VservManager* GetInstance();
		void DisplayAd(QString zoneId);
		void RenderAd(QString zoneId, bb::cascades::Container*);
		void setBirthDate(QString birthDate);
		void setAge(QString age);
		void setGender(QString gender);
		void setShowAt(QString showAt);
		void setPartnerId(QString partnerId);
		void setStoreFrontId(QString storeFrontId);
		void setCity(QString city);
		void setCountry(QString country);
		void setEmail(QString email);
		void setConnectionTimeOut(int timeOut);
	private:
		VservManager(); // constructor
		~VservManager(); // destructor
	private:
		static VservManager* mVservManager;	// singleton instance
};

#endif /* VSERVMANAGER_HPP_ */
