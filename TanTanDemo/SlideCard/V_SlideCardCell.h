//
//  V_SlideCardCell.h
//  TanTanDemo
//
//  Created by zhujiamin on 2016/11/16.
//  Copyright © 2016年 zhujiamin. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PanDirection) {
    PanDirectionNone = 0,
    PanDirectionLeft,
    PanDirectionRight,
};

typedef NS_ENUM(NSInteger, CardState) {
    FirstCard = 0,
    SecondCard,
    ThirdCard,
    OtherCard,
};

@protocol V_SlideCardCellDelegate;

@interface V_SlideCardCell : UIView

@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, readonly) CGPoint originalCenter;

/** 中心Y偏移值*/
@property (nonatomic) CGFloat offsetY;

@property (nonatomic, weak)   id<V_SlideCardCellDelegate> delegate;

/** cell当前所处的状态 */
@property (nonatomic)         CardState     currentState;
/** cell之间的Y偏移，显示层叠效果*/
@property (nonatomic)         CGFloat       cellMarginY;

- (void)hideToLeft;
- (void)setUpConfig;
- (void)initUI;

- (void)moveWithParams:(NSDictionary *)params;

@end

@protocol V_SlideCardCellDelegate <NSObject>

- (void)setAnimatingState:(BOOL)animating;

- (void)loadNewData:(V_SlideCardCell *)cell;

@end