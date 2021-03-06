/**
 * @file UserInterface.h
 * @brief 走行体が走り出す前にユーザが入力するインターフェースを提供するクラス
 * @author Keisuke MORI
 *
 * 簡単な使い方は以下の通りです。
 *
 * ```
 * UserInterface ui;
 * ui.inputFirstCode(); // 初期位置コードを入力している
 *                      // ループになっており、ループを抜けたら次の処理に進める
 * int32_t firstCode = ui.getFirstCode(); // 入力した初期位置コードを取得する
 * ```
 */
#ifndef __USER_INTERFACE__
#define __USER_INTERFACE__

#include "ColorSensor.h"
#include "FirstCode.h"
#include "ev3api.h"
#include "util.h"
#include <string>

using namespace ev3api;

/*! @class UserInterface UserInterface.h "UserInterface.h"
 * @brief 走行体が走り出す前にユーザが入力するインターフェースを提供するクラス
 */
class UserInterface {
 public:
  /**
   * 初期位置コードを入力する。
   * whileループに入っており、ENTERボタンを押すまでループを抜けることはない。
   * UPボタンとDOWNボタンで数字の大小を選択し、RightボタンとLeftボタンで変更する数字の桁数を選択する。
   */
  void inputFirstCode();
  void setBrightness(ColorSensor& colorSensor, int8_t& brightness, const char* str);
  void setBrightnessWithColor(ColorSensor& colorSensor, int16_t& brightness, const char* str);
  /**
   * 初期位置コードを返す。
   * FirstCodeクラスに依存する。
   *
   * @return 初期位置コード FirstCodeクラスのgetFirstCodeメンバ関数の値をそのまま返す
   */
  int32_t getFirstCode();

 private:
  /**
   * 現在操作している初期位置コードの桁数に応じたカーソルの場所を示すテキストを取得する。
   * inputFirstCodeメンバ関数の桁数や文字の大きさに依存する。
   *
   * @param 現在操作している初期位置コードの桁数
   * @return カーソルの場所を示すテキスト 1桁から5桁以外の場所に存在している場合は全選択を行う
   */
  char* getCurrentDigitText(int8_t);

  /**
   * 初期位置コードクラスのインスタンス
   */
  FirstCode firstCode;
};

#endif
