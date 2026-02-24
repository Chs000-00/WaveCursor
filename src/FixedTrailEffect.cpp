#include <Geode/Geode.hpp>
#include <Geode/binding/GhostTrailEffect.hpp>

#include "FixedTrailEffect.hpp"

using namespace geode::prelude;

// // local variable allocation has failed, the output may be wrong!
// void GhostTrailEffect::trailSnapshot(GhostTrailEffect *this, float p0)
// {
//   PlayerObject *m_playerObject; // x21
//   cocos2d::CCSprite *v4; // x0
//   cocos2d::CCTexture2D *v5; // x1
//   cocos2d::CCSprite *v6; // x20
//   void (__fastcall *setDisplayFrame)(cocos2d::CCSprite *__hidden, cocos2d::CCSpriteFrame *); // x23
//   cocos2d::CCSpriteFrame *v8; // x0
//   const cocos2d::CCPoint *v9; // x0
//   float v10; // s9
//   float v11; // s0
//   PlayerObject *v12; // x0
//   float v13; // s8
//   char isFlipX; // w0
//   char isFlipY; // w0
//   void (__fastcall *setRotation)(cocos2d::CCSprite *__hidden, float); // x23
//   cocos2d::CCLayer *m_objectLayer; // x23
//   PlayerObject *v18; // x0
//   int (__fastcall *getZOrder)(cocos2d::CCNode *__hidden); // x1
//   void (__fastcall *addChild_0)(cocos2d::CCNode *__hidden, cocos2d::CCNode *, int); // x21
//   int v21; // w0
//   cocos2d::CCSprite_vtbl *v22; // x2
//   cocos2d::CCFiniteTimeAction *v23; // x21
//   __int64 v24; // x0
//   cocos2d::CCAction *v25; // x0
//   cocos2d::CCFiniteTimeAction *v26; // x23
//   __int64 v27; // x21
//   __int64 v28; // x0
//   cocos2d::CCAction *v29; // x0
//   cocos2d::CCScaleTo *v30; // x0
//   cocos2d::CCScaleTo *v31; // x21
//   __int64 v32; // x0
//   cocos2d::CCAction *v33; // x0
//   float m_fadeInterval; // s8
//   float v35; // s0
//   cocos2d::CCAction *v36; // x0
//   float v37; // [xsp+70h] [xbp+70h]
//   cocos2d::CCPoint v38; // [xsp+80h] [xbp+80h] BYREF
//   __int64 v39; // [xsp+88h] [xbp+88h] BYREF
//   __int64 v40; // [xsp+90h] [xbp+90h] BYREF
//   __int64 v41; // [xsp+98h] [xbp+98h] BYREF
//   cocos2d::CCPoint v42; // [xsp+A0h] [xbp+A0h] BYREF

//   m_playerObject = this->m_playerObject;
//   if ( !m_playerObject )
//     m_playerObject = this->m_iconSprite;
//   v4 = (this->m_iconSprite->getTexture)(this->m_iconSprite, *&p0);
//   v6 = cocos2d::CCSprite::createWithTexture(v4, v5);
//   if ( this->m_iconSprite->displayFrame(this->m_iconSprite) )
//   {
//     setDisplayFrame = v6->setDisplayFrame;
//     v8 = this->m_iconSprite->displayFrame(this->m_iconSprite);
//     setDisplayFrame(v6, v8);
//   }
//   (v6->setBlendFunc)(v6, *&this->m_blendFunc);
//   v9 = m_playerObject->getPosition(m_playerObject);
//   cocos2d::CCPoint::CCPoint(&v38, v9);
//   if ( this->m_position.x != *&dword_1210A50 || this->m_position.y != *&dword_1210A54 )
//   {
//     cocos2d::CCNode::convertToWorldSpace(&v39, this->m_iconSprite, &this->m_position);
//     cocos2d::CCNode::convertToWorldSpace(&v40, this->m_iconSprite, &dword_1210A50);
//     cocos2d::CCPoint::operator-(&v39, &v40);
//     cocos2d::CCPoint::operator+(&v38, &v41);
//     cocos2d::CCPoint::operator=(&v38, &v42);
//   }
//   v10 = this->m_iconSprite->getScaleX(this->m_iconSprite) * this->m_playerScale;
//   v11 = this->m_iconSprite->getScaleY(this->m_iconSprite);
//   v12 = this->m_playerObject;
//   v13 = v11 * this->m_playerScale;
//   if ( v12 && v12->getScaleY(v12) < 0.0 )
//     v13 = -v13;
//   v6->setPosition(v6, &v38);
//   isFlipX = cocos2d::CCSprite::isFlipX(m_playerObject);
//   cocos2d::CCSprite::setFlipX(v6, isFlipX);
//   isFlipY = cocos2d::CCSprite::isFlipY(m_playerObject);
//   cocos2d::CCSprite::setFlipY(v6, isFlipY);
//   setRotation = v6->setRotation;
//   m_playerObject->getRotation(m_playerObject);
//   (setRotation)(v6);
//   v6->setColor(v6, &this->m_color);
//   v6->setScaleX(v6, v10);
//   v6->setScaleY(v6, v13);
//   m_objectLayer = this->m_objectLayer;
//   if ( !m_objectLayer )
//     m_objectLayer = m_playerObject->getParent(m_playerObject);
//   v18 = m_playerObject;
//   getZOrder = m_playerObject->getZOrder;
//   addChild_0 = m_objectLayer->addChild_0;
//   v21 = getZOrder(v18);
//   addChild_0(m_objectLayer, v6, v21 - 1);
//   v22 = v6->cocos2d::CCNodeRGBA::cocos2d::CCNode::cocos2d::CCObject::cocos2d::CCCopying::__vftable;
//   if ( this->m_scaleTwice )
//   {
//     v22->setOpacity(v6, 0);
//     v6->setScale(v6, this->m_ghostScale * this->m_playerScale);
//     v26 = cocos2d::CCFadeTo::create(this->m_fadeInterval * 0.5, this->m_opacity);
//     v27 = cocos2d::CCFadeTo::create(this->m_fadeInterval * 0.5, 0);
//     v28 = cocos2d::CCCallFunc::create(v6, 520);
//     v29 = cocos2d::CCSequence::create(v26, v27, v28, 0);
//     v30 = cocos2d::CCNode::runAction(v6, v29);
//     if ( this->m_ghostScale != 1.0 )
//     {
//       v31 = cocos2d::CCScaleTo::create(v30, this->m_fadeInterval * 0.5, 1.0);
//       v32 = cocos2d::CCScaleTo::create(v31, this->m_fadeInterval * 0.5, this->m_ghostScale * this->m_playerScale);
//       v33 = cocos2d::CCSequence::create(v31, v32, 0);
//       cocos2d::CCNode::runAction(v6, v33);
//     }
//   }
//   else
//   {
//     v22->setOpacity(v6, this->m_opacity);
//     v23 = cocos2d::CCFadeTo::create(this->m_fadeInterval, 0);
//     v24 = cocos2d::CCCallFunc::create(v6, 520);
//     v25 = cocos2d::CCSequence::create(v23, v24, 0);
//     cocos2d::CCNode::runAction(v6, v25);
//     if ( this->m_ghostScale != 1.0 )
//     {
//       m_fadeInterval = this->m_fadeInterval;
//       v37 = (v6->getScaleX(v6) * this->m_ghostScale) * this->m_playerScale;
//       v35 = v6->getScaleY(v6);
//       v36 = cocos2d::CCScaleTo::create(m_fadeInterval, v37, (v35 * this->m_ghostScale) * this->m_playerScale);
//       cocos2d::CCNode::runAction(v6, v36);
//     }
//   }
// }
void fixedTrailSnapshot(GhostTrailEffect* effect, float p0) {
//   CCSprite* effect->m_iconSprite; // x21
  cocos2d::CCSprite* v4; // x0
  cocos2d::CCTexture2D* v5; // x1
  cocos2d::CCSprite* v6; // x20
  cocos2d::CCSpriteFrame* v8; // x0
  const cocos2d::CCPoint* v9; // x0
  float v10; // s9
  float v11; // s0
  CCSprite* v12; // x0
  float v13; // s8
  char isFlipX; // w0
  char isFlipY; // w0
  cocos2d::CCLayer* m_objectLayer; // x23
  CCSprite* v18; // x0
  int v21; // w0
  cocos2d::CCFiniteTimeAction* v23; // x21
  __int64 v24; // x0
  cocos2d::CCAction* v25; // x0
  cocos2d::CCFiniteTimeAction* v26; // x23
  CCFadeTo* v27; // x21
  CCCallFunc* v28; // x0
  cocos2d::CCAction* v29; // x0
  cocos2d::CCAction* v30; // x0
  cocos2d::CCScaleTo* v31; // x21
  CCScaleTo* v32; // x0
  cocos2d::CCAction* v33; // x0
  float m_fadeInterval; // s8
  float v35; // s0
  cocos2d::CCAction* v36; // x0
  float v37; // [xsp+70h] [xbp+70h]
  cocos2d::CCPoint v38; // [xsp+80h] [xbp+80h] BYREF
//   __int64 v39; // [xsp+88h] [xbp+88h] BYREF
//   __int64 v40; // [xsp+90h] [xbp+90h] BYREF
//   __int64 v41; // [xsp+98h] [xbp+98h] BYREF
  cocos2d::CCPoint v42; // [xsp+A0h] [xbp+A0h] BYREF

  effect->m_iconSprite = effect->m_iconSprite;
  //v4 = (effect->m_iconSprite->getTexture)(effect->m_iconSprite,* &p0);
//   v6 = cocos2d::CCSprite::createWithTexture(v4, v5);
//   if ( effect->m_iconSprite->displayFrame(effect->m_iconSprite) )
//   {
//     setDisplayFrame = v6->setDisplayFrame;
//     v8 = effect->m_iconSprite->displayFrame(effect->m_iconSprite);
//     setDisplayFrame(v6, v8);
//   }

  v6->setBlendFunc(*&effect->m_blendFunc);

  v10 = effect->m_iconSprite->getScaleX() * effect->m_playerScale;
  v11 = effect->m_iconSprite->getScaleY();
  v12 = effect->m_iconSprite;
  v13 = v11 * effect->m_playerScale;
  if ( v12 && v12->getScaleY() < 0.0 )
    v13 = -v13;
  v6->setPosition(v38);
  isFlipX = effect->m_iconSprite->isFlipX();
  v6->setFlipX(isFlipX);
  isFlipY = effect->m_iconSprite->isFlipY();
  v6->setFlipY(isFlipY);
  effect->m_iconSprite->getRotation();
  v6->setColor(effect->m_color);
  v6->setScaleX(v10);
  v6->setScaleY(v13);
  m_objectLayer = effect->m_objectLayer;
  if ( !m_objectLayer )
    m_objectLayer = (CCLayer*)effect->m_iconSprite->getParent();
  v21 = effect->m_iconSprite->getZOrder();
  m_objectLayer->addChild(v6, v21 - 1);
  if ( effect->m_scaleTwice )
  {
    v6->setOpacity(0);
    v6->setScale(effect->m_ghostScale * effect->m_playerScale);
    v26 = cocos2d::CCFadeTo::create(effect->m_fadeInterval * 0.5, effect->m_opacity);
    v27 = cocos2d::CCFadeTo::create(effect->m_fadeInterval * 0.5, 0);
    // v28 = cocos2d::CCCallFunc::create(v6, 520);
    v29 = cocos2d::CCSequence::create(v26, v27, v28, 0);
    v30 = v6->runAction(v29);
    if ( effect->m_ghostScale != 1.0 )
    {
      v31 = cocos2d::CCScaleTo::create(effect->m_fadeInterval * 0.5, 1.0);
      v32 = cocos2d::CCScaleTo::create(effect->m_fadeInterval * 0.5, effect->m_ghostScale * effect->m_playerScale);
      v33 = cocos2d::CCSequence::create(v31, v32, 0);
      v6->runAction(v33);
    }
  }
  else
  {
    v6->setOpacity(effect->m_opacity);
    v23 = cocos2d::CCFadeTo::create(effect->m_fadeInterval, 0);
    //v24 = cocos2d::CCCallFunc::create(v6, 520);
    v25 = cocos2d::CCSequence::create(v23, v24, 0);
    v6->runAction(v25);
    if ( effect->m_ghostScale != 1.0 )
    {
      m_fadeInterval = effect->m_fadeInterval;
      v37 = (v6->getScaleX() * effect->m_ghostScale) * effect->m_playerScale;
      v35 = v6->getScaleY();
      v36 = cocos2d::CCScaleTo::create(m_fadeInterval, v37, (v35 * effect->m_ghostScale) * effect->m_playerScale);
      v6->runAction(v36);
    }
  }
}