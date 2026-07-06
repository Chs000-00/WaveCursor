#include <Geode/Geode.hpp>
#include <Geode/modify/GhostTrailEffect.hpp>

#include "FixedTrailEffect.hpp"

using namespace geode::prelude;

void BetterGhostTrailEffect::fixedTrailSnapshot(float p0) {
  // PlayerObject *m_playerObject; // rdi
  // struct cocos2d::CCTexture2D *texture; // rax
  // struct cocos2d::CCSprite *sprite; // r14
  // cocos2d::CCSpriteFrame *newFrame; // rax
  // const struct cocos2d::CCPoint *positionToCreateAt; // rax
  // PlayerObject *playerObject2; // rcx
  // bool isFlipX; // al
  // bool isFlipY; // al
  // cocos2d::CCLayer *m_objectLayer; // r15
  // int zOrder; // eax
  // cocos2d::CCRGBAProtocol *ignore_rgbProtocol; // rcx
  // void (__fastcall *setOpacity)(cocos2d::CCRGBAProtocol *__hidden, GLubyte); // r8
  // struct cocos2d::CCFadeTo *fadeToAction; // rbx
  // __int64 callFuncAction; // rax
  // struct cocos2d::CCSequence *sequenceAction; // rax
  // double spriteScaleY; // xmm0_8
  // float v22; // xmm6_4
  // struct cocos2d::CCScaleTo *allSequence; // rax
  // struct cocos2d::CCFadeTo *fadeToOldAction_st; // rdi
  // struct cocos2d::CCFadeTo *fadeToZeroAction_st; // rbx
  // __int64 callFuncAction_st; // rax
  // struct cocos2d::CCSequence *fadeSequence_st; // rax
  // struct cocos2d::CCScaleTo *scaleToMaxAction_st; // rbx
  // struct cocos2d::CCScaleTo *scaleToPScaleAction_st; // rax
  // char v30[8]; // [rsp+20h] [rbp-58h] BYREF
  // char v31[8]; // [rsp+28h] [rbp-50h] BYREF
  // cocos2d::CCPoint point; // [rsp+80h] [rbp+8h] BYREF
  // struct cocos2d::CCPoint v33; // [rsp+90h] [rbp+18h] BYREF
  // struct cocos2d::CCPoint v34; // [rsp+98h] [rbp+20h] BYREF

  // m_playerObject = this->m_playerObject;
  // if ( !m_playerObject )
  // {
  //   m_playerObject = (PlayerObject *)this->m_iconSprite;
  // }
  // texture = this->m_iconSprite->getTexture();
  // sprite = cocos2d::CCSprite::createWithTexture(texture);
  // if ( this->m_iconSprite->displayFrame() )
  // {
  //   newFrame = this->m_iconSprite->displayFrame();
  //   sprite->setDisplayFrame(newFrame);
  // }
  // ((void (__fastcall *)(cocos2d::CCTextureProtocol *, _QWORD))sprite->setBlendFunc)(
  //   &sprite->cocos2d::CCTextureProtocol,
  //   *(_QWORD *)&this->m_blendFunc);
  // positionToCreateAt = m_playerObject->getPosition();
  // cocos2d::CCPoint::CCPoint(&point, positionToCreateAt);
  // if ( this->m_position.x != *(float *)&dword_1406C14A8 || this->m_position.y != *(float *)&dword_1406C14AC )
  // {
  //   this->m_iconSprite->cocos2d::CCNode::convertToWorldSpace(v34);
  //   this->m_iconSprite->cocos2d::CCNode::convertToWorldSpace(v33);
  //   cocos2d::CCPoint::operator-(&v34, v30, &v33);
  //   cocos2d::CCPoint::operator+(&point, v31, v30);
  //   cocos2d::CCPoint::operator=(&point, v31);
  // }
  // this->m_iconSprite->getScaleX();
  // this->m_iconSprite->getScaleY();
  // playerObject2 = this->m_playerObject;
  // if ( playerObject2 )
  // {
  //   playerObject2->getScaleY();
  // }
  // sprite->setPosition(point);
  // isFlipX = m_playerObject->isFlipX();
  // sprite->setFlipX(isFlipX);
  // isFlipY = m_playerObject->isFlipY();
  // sprite->setFlipY(isFlipY);
  // m_playerObject->getRotation();
  // ((void (__fastcall *)(struct cocos2d::CCSprite *))v12->setRotation)(sprite);
  // sprite->setColor(&sprite->cocos2d::CCRGBAProtocol, &this->m_color);
  // ((void (__fastcall *)(struct cocos2d::CCSprite *))sprite->setScaleX)(sprite);
  // ((void (__fastcall *)(struct cocos2d::CCSprite *))sprite->setScaleY)(sprite);
  // m_objectLayer = this->m_objectLayer;
  // if ( !m_objectLayer )
  // {
  //   m_objectLayer = (cocos2d::CCLayer *)m_playerObject->getParent(m_playerObject);
  // }
  // zOrder = m_playerObject->getZOrder();
  // m_objectLayer->addChild(sprite, zOrder - 1);
  // if ( this->m_scaleTwice )
  // {
  //   sprite->setOpacity(0);
  //   ((void (__fastcall *)(struct cocos2d::CCSprite *))sprite->setScale_0)(sprite);
  //   fadeToOldAction_st = cocos2d::CCFadeTo::create(this->m_fadeInterval * 0.5, (int)this->m_opacity);
  //   fadeToZeroAction_st = cocos2d::CCFadeTo::create(this->m_fadeInterval * 0.5, 0);
  //   callFuncAction_st = cocos2d::CCCallFunc::create(sprite, sub_14003BE70);
  //   fadeSequence_st = cocos2d::CCSequence::create(fadeToOldAction_st, fadeToZeroAction_st, callFuncAction_st, 0);
  //   cocos2d::CCNode::runAction(sprite, fadeSequence_st);
  //   if ( this->m_ghostScale == 1.0 )
  //   {
  //     return;
  //   }
  //   scaleToMaxAction_st = cocos2d::CCScaleTo::create(this->m_fadeInterval * 0.5, 1.0);
  //   scaleToPScaleAction_st = cocos2d::CCScaleTo::create(this->m_fadeInterval * 0.5, this->m_playerScale * this->m_ghostScale);
  //   allSequence = (struct cocos2d::CCScaleTo *)cocos2d::CCSequence::create(
  //                                                scaleToMaxAction_st,
  //                                                scaleToPScaleAction_st,
  //                                                0);
  // }
  // else
  // {
  //   sprite->setOpacity((int)this->m_opacity);
  //   fadeToAction = cocos2d::CCFadeTo::create(this->m_fadeInterval, 0);
  //   callFuncAction = cocos2d::CCCallFunc::create(sprite, sub_14003BE70);
  //   sequenceAction = cocos2d::CCSequence::create(fadeToAction, callFuncAction, 0);
  //   runAction(sprite, sequenceAction);
  //   if ( this->m_ghostScale == 1.0 )
  //   {
  //     return;
  //   }
  //   spriteScaleY = ((double (__fastcall *)(struct cocos2d::CCSprite *))sprite->getScaleY)(sprite);
  //   v22 = *(float *)&spriteScaleY * this->m_ghostScale;
  //   *(float *)&spriteScaleY = sprite->getScaleX(sprite);
  //   allSequence = CCScaleTo::create(
  //                   this->m_fadeInterval,
  //                   (float)(*(float *)&spriteScaleY * this->m_ghostScale) * this->m_playerScale,
  //                   v22 * this->m_playerScale);
  // }
  // cocos2d::CCNode::runAction(sprite, allSequence);
}