//
// アプリ雛形
// 

// GameTemplateで用意されている機能
// の全てをインクルード
#include "lib/framework.hpp"


// 
// メインプログラム
// 
int main() {
  // アプリウインドウを生成
  // TIPS:必ず、最初に生成する事
  AppEnv env(640, 480);

  while (env.isOpen()) {
    // 開始
    env.begin();
    
    // 
    // アプリの処理をここに書く
    // 
    
    // 終了
    env.end();
  }
}
