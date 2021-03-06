//
//  InAppPurchaser.h
//  GuessWord
//
//  Created by green wayne on 13-8-16.
//  Copyright (c) 2013年 green wayne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
@class InAppPurchaser;
@class Product;

/////
@protocol InAppPurchaseProtocol <NSObject>
-(BOOL)canMakePayments;
-(void)purchaseProduct:(Product *)product;
-(void)restoreCompletedTransactions;
-(void)retry;
@end
/////

/////
@protocol InAppPurchaseDelegate <NSObject>
-(void)inAppPurchaseStarted:(InAppPurchaser*)purchaser;
-(void)inAppPurchaseSuccess:(InAppPurchaser*)purchaser;
-(void)inAppPurchase:(InAppPurchaser*)purchaser failedWithError:(NSError*)error;
@end
/////

/////
@interface InAppPurchaser : NSObject<InAppPurchaseProtocol,InAppPurchaseDelegate>
@property(nonatomic,assign)id<InAppPurchaseDelegate> delegate;
@property(nonatomic,strong,readonly)Product* currentProduct;//正在交易中的商品
@property(nonatomic,strong,readonly)id currentReceipt;//当前交易得到的收据
@end
/////

/////
@interface InAppPurchaserApple : InAppPurchaser<SKPaymentTransactionObserver,SKProductsRequestDelegate>
- (void) requestProductDataWithProductIds:(NSSet *)productIds;
@end
/////


/////
@interface Product : NSObject
@property(nonatomic, strong) NSString* remoteId;
@property(nonatomic, strong) NSString *identifier;
@property(nonatomic, strong) NSString *localizedDescription;
@property(nonatomic, strong) NSString *localizedTitle;
@property(nonatomic, strong) NSDecimalNumber *price;
@property(nonatomic, strong) NSLocale *priceLocale;
@property(nonatomic, strong) NSString *priceLocaleString;
@property(nonatomic, assign) NSInteger quantity;
@property(nonatomic, strong) id extraData;
@end
/////