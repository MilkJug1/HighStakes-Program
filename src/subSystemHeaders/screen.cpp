#include "globals.hpp"
#include "main.h"

// TODO: Style it with the School colors and make it a bit nicer to look at.
// TODO: find a way to handle control switching, maybe a variable that we can
// look at that would be used to dictate which control style we use?
// TODO: Figuring out one wants to do the Driver control tab
// NOTE: Maybe we could implement another screen for skills?
//
static lv_res_t btnSwitcher(lv_obj_t *btn) {

  uint8_t id = lv_obj_get_free_num(btn);

  if (id == 1)
    printf("Switched to Arcade Control\n Please Implement this!\n");
  controlScheme = 1;
  printf("%i\n)", controlScheme);
  if (id == 0)
    printf("Switched toTank Control\n Please Implement this!\n");
  controlScheme = 0;
  printf("%i\n", controlScheme);

  return LV_RES_OK;
}

static lv_res_t AutonSwitcher(lv_obj_t *btn, const char *txt) {
  // TODO: implement functionality for auton switcher
  printf("Implement this for button :%s\n", txt);

  return LV_RES_OK;
}

void screenInit() {

  lv_obj_t *tabview;

  tabview = lv_tabview_create(lv_scr_act(), NULL);

  lv_obj_t *tab1 = lv_tabview_add_tab(tabview, "Auton Select");
  lv_obj_t *tab2 = lv_tabview_add_tab(tabview, "Drive Select");
  lv_obj_t* tab3 = lv_tabview_add_tab(tabview, "Skills Auton");

    static lv_style_t bg_btn_background;
    bg_btn_background.body.main_color = LV_COLOR_HEX(0x4d0000);
    bg_btn_background.text.font = &lv_font_dejavu_20;

    lv_tabview_set_style(tabview, LV_TABVIEW_STYLE_BTN_BG, &bg_btn_background);

  lv_obj_t *label1 = lv_label_create(tab1, NULL);
  lv_obj_t *label2 = lv_label_create(tab1, NULL);

  // lv_obj_t *autonName = lv_label_create(tab1, NULL);
  lv_obj_align(label1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 10);
  lv_obj_align(label2, NULL, LV_ALIGN_IN_LEFT_MID, 0, 0);
  // lv_obj_align(autonName, NULL, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
  //
  //
  static const char *btnm_map[] = {"btn1", "btn2", "btn3", "btn4", ""};
  lv_obj_t *switcherBtns = lv_btnm_create(tab1, NULL);

  lv_btnm_set_map(switcherBtns, btnm_map);

  lv_btnm_set_action(switcherBtns, AutonSwitcher);

  lv_obj_set_size(switcherBtns, LV_HOR_RES, LV_VER_RES / 2);

  static lv_style_t style_bg;
  // lv_style_copy(&style_bg, &lv_style_plain);
  // style_bg.body.main_color = LV_COLOR_SILVER;
  // style_bg.body.grad_color = LV_COLOR_SILVER;
  // style_bg.body.padding.hor = 0;
  // style_bg.body.padding.ver = 0;
  // style_bg.body.padding.inner = 0;
  //
  style_bg.text.color = LV_COLOR_WHITE;

  /*Create 2 button styles*/
  static lv_style_t style_btn_rel;
  static lv_style_t style_btn_pr;
  lv_style_copy(&style_btn_rel, &lv_style_btn_rel);
  // style_btn_rel.body.main_color = LV_COLOR_MAKE(0x30, 0x30, 0x30);
  // style_btn_rel.body.grad_color = LV_COLOR_BLACK;
  // style_btn_rel.body.border.color = LV_COLOR_SILVER;
  // style_btn_rel.body.border.width = 1;
  // style_btn_rel.body.border.opa = LV_OPA_50;
  // style_btn_rel.body.radius = 0;
  style_btn_rel.text.color = LV_COLOR_WHITE;
  //

  lv_style_copy(&style_btn_pr, &style_btn_rel);

  lv_btnm_set_style(switcherBtns, LV_BTNM_STYLE_BG, &style_btn_rel);
  style_btn_pr.body.main_color = LV_COLOR_MAKE(0x55, 0x96, 0xd8);
  style_btn_pr.body.grad_color = LV_COLOR_MAKE(0x37, 0x62, 0x90);
  style_btn_pr.text.color = LV_COLOR_MAKE(0xbb, 0xd5, 0xf1);

  lv_obj_t *controlArcade = lv_btn_create(tab2, NULL);
  lv_obj_t *controlTank = lv_btn_create(tab2, NULL);

  lv_obj_set_free_num(controlArcade, 1);
  lv_obj_set_free_num(controlTank, 0);

  lv_obj_t *controlText = lv_label_create(controlArcade, NULL);
  lv_obj_t *controlText1 = lv_label_create(controlTank, NULL);

  lv_label_set_text(controlText, "Arcade Control");
  lv_label_set_text(controlText1, "Tank Control");

  lv_btn_set_action(controlArcade, LV_BTN_ACTION_PR, btnSwitcher);
  lv_btn_set_action(controlTank, LV_BTN_ACTION_PR, btnSwitcher);

  lv_obj_align(controlTank, NULL, LV_ALIGN_IN_RIGHT_MID, 0, 0);

  lv_obj_t *switchControl = lv_sw_create(tab2, NULL);
  lv_obj_align(switchControl, NULL, LV_ALIGN_CENTER, 0, 0);
}
