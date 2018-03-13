/*
 * SpInAppManager.h
 *
 *  Created on: Sep 19, 2012
 *      Author: ugurkilic
 */

#ifndef SPINAPPMANAGER_H_
#define SPINAPPMANAGER_H_

#include <pthread.h>

#include "SpDefs.h"
#include "SpEventGroup.h"

class SpInAppManager;
static SpInAppManager *inAppManager = NULL;


class SpInAppManager {
public:
    /**
     * Constructor
     */
	SpInAppManager();

    /**
     * Destructor
     */
	virtual ~SpInAppManager();

    /**
     * Singleton Creator and Holder
     */
    static SpInAppManager* GetInAppManager();

    /**
     * Set latest Event group
     */
    void SetEvents(SpEventGroup *eventGroup);

    /**
     * Called when product list is received from server
     */
    void ProductsReceived(bool result = true);

    /**
     * Called when products which are already purchased are received from server
     * @param productsVector Array that holds product keys
     */
    void ProductsAlreadyPurchased(std::vector<SpBrString *> productsVector);

    /**
     * Called when billing availability check finished
     * @param isBillingAvailable Holds billing availability status
     */
    void BillingAvailable(bool isBillingAvailable);

    /**
     * Called when a transaction process is finished
     * @param key Product key if successful
     */
    void ProcessCompleted(TTransactionResult code, SpBrString *key = NULL);

    /**
     *
     */
    void RetrievePurchasesFinished(bool result);

private:
    SpEventGroup *events;
    pthread_mutex_t lock;
};

#endif /* SPINAPPMANAGER_H_ */
