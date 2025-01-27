#include "liblvgl/lvgl.h"
#include "main.h"
#include <cstddef>
#include <cstdint>

// TODO: Style it with the School colors and make it a bit nicer to look at.
// TODO: find a way to handle control switching, maybe a variable that we can
// look at that would be used to dictate which control style we use?
// TODO: Figuring out one wants to do the Driver control tab
// NOTE: Maybe we could implement another screen for skills?
// NOTE: Been a while since I've dealt with OOP in C++, Im a bit used to Rust,
// Zig, and C at the moment, but classes may or may not help me out right now
//
//
// static void btnSwitcher(lv_event_t *btn) {
//
//   uint8_t id = lv_obj_get_free_num(btn);
//
//   if (id == 1)
//     printf("Switched to Arcade Control\n Please Implement this!\n");
//   controlScheme = 1;
//   printf("%i\n)", controlScheme);
//   if (id == 0)
//     printf("Switched toTank Control\n Please Implement this!\n");
//   controlScheme = 0;
//   printf("%i\n", controlScheme);
//
//   return LV_RES_OK;
// }
//

// This will be moved into another file, just here for testing purposes.
// TODO: Handle Auton in seperate file
static void event_handler(lv_event_t *e) {
  lv_obj_t *obj = lv_event_get_target(e); 
  uint32_t id = lv_btnmatrix_get_selected_btn(obj); // We create a variable of the index of which button has been selected, since its an array
  printf("Button %d is %s\n", id, (lv_btnmatrix_has_btn_ctrl(obj, id,
  LV_BTNMATRIX_CTRL_CHECKED) ? "selected" : "not selected")); // See which button has been checked with the "lv_matrix_get_selected_btn()"
    // This switch case is how we are going to handle dealing with the selecting of different Autons.

}

void screenInit() {

  lv_obj_t *tabview;

  tabview = lv_tabview_create(lv_scr_act(), 1, 100);

  lv_obj_t *tab1 = lv_tabview_add_tab(tabview, "Auton Select");
  lv_obj_t *tab2 = lv_tabview_add_tab(tabview, "Drive Select");
  lv_obj_t *tab3 = lv_tabview_add_tab(tabview, "Skills Auton");

  static lv_style_t bg_btn_background;
  // lv_tabview_set_style(tabview, LV_TABVIEW_STYLE_BTN_BG, &bg_btn_background);

  lv_obj_t *label1 = lv_label_create(tab1);
  lv_obj_t *label2 = lv_label_create(tab1);

  lv_obj_t *autonName = lv_label_create(tab1);

  // lv_obj_t *autonName = lv_label_create(tab1, NULL);
  lv_obj_align(label1, LV_ALIGN_RIGHT_MID, 0, 10);
  lv_obj_align(label2, LV_ALIGN_LEFT_MID, 0, 0);
  // lv_obj_align(autonName, NULL, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
  //
  //
  static const char *btnm_map[] = {"btn1", "btn2", "\n", "btn3", "btn4", ""};
  lv_obj_t *switcherBtns = lv_btnmatrix_create(tab1);

  lv_btnmatrix_set_map(switcherBtns, btnm_map);

  lv_obj_add_event_cb(switcherBtns, event_handler, LV_EVENT_VALUE_CHANGED,
                      NULL);

  lv_obj_set_size(switcherBtns, LV_HOR_RES, LV_VER_RES / 2);
  lv_btnmatrix_set_btn_ctrl_all(switcherBtns, LV_BTNMATRIX_CTRL_CHECKABLE);

  // lv_btnmatrix_set_btn_ctrl(switcherBtns,  0,  LV_BTNMATRIX_CTRL_CHECKABLE);
  // lv_btnmatrix_set_btn_ctrl(switcherBtns,  1,  LV_BTNMATRIX_CTRL_CHECKABLE);
  // lv_btnmatrix_set_btn_ctrl(switcherBtns,  2,  LV_BTNMATRIX_CTRL_CHECKABLE);
  // lv_btnmatrix_set_btn_ctrl(switcherBtns,  3,  LV_BTNMATRIX_CTRL_CHECKABLE);

  lv_btnmatrix_set_one_checked(switcherBtns, true);
  // lv_btnmatrix_set_btn_ctrl(switcherBtns, 1, LV_BTNMATRIX_CTRL_CHECKED);
  lv_obj_center(switcherBtns);

  lv_label_set_text(autonName, "Test");
  lv_obj_set_y(autonName, -10);

  lv_obj_align(autonName, LV_ALIGN_BOTTOM_MID, 0, 0);
  static lv_style_t style_bg;

  lv_style_init(&style_bg);
  lv_style_set_bg_color(&style_bg, lv_color_hex(0xa03060));
  // lv_style_copy(&style_bg, &lv_style_plain);
  // style_bg.body.main_color = LV_COLOR_SILVER;
  // style_bg.body.grad_color = LV_COLOR_SILVER;
  // style_bg.body.padding.hor = 0;
  // style_bg.body.padding.ver = 0;
  // style_bg.body.padding.inner = 0;
  //
  // style_bg.text.color = LV_COLOR_WHITE;
  lv_obj_set_style_bg_color(tabview, lv_palette_main(LV_PALETTE_GREY), 0);
  /*Create 2 button styles*/
  static lv_style_t style_btn_rel;
  static lv_style_t style_btn_pr;
  // lv_style_copy(&style_btn_rel, &lv_style_btn_rel);
  // style_btn_rel.body.main_color = LV_COLOR_MAKE(0x30, 0x30, 0x30);
  // style_btn_rel.body.grad_color = LV_COLOR_BLACK;
  // style_btn_rel.body.border.color = LV_COLOR_SILVER;
  // style_btn_rel.body.border.width = 1;
  // style_btn_rel.body.border.opa = LV_OPA_50;
  // style_btn_rel.body.radius = 0;
  // style_btn_rel.text.color = LV_COLOR_WHITE;
  //

  // lv_style_copy(&style_btn_pr, &style_btn_rel);

  // lv_btnm_set_style(switcherBtns, LV_BTNM_STYLE_BG, &style_btn_rel);
  // style_btn_pr.body.main_color = LV_COLOR_MAKE(0x55, 0x96, 0xd8);
  // style_btn_pr.body.grad_color = LV_COLOR_MAKE(0x37, 0x62, 0x90);
  // style_btn_pr.text.color = LV_COLOR_MAKE(0xbb, 0xd5, 0xf1);
  //
  lv_obj_t *controlArcade = lv_btn_create(tab2);
  lv_obj_t *controlTank = lv_btn_create(tab2);

  // lv_obj_set_free_num(controlArcade, 1);
  // lv_obj_set_free_num(controlTank, 0);

  lv_obj_t *controlText = lv_label_create(controlArcade);
  lv_obj_t *controlText1 = lv_label_create(controlTank);

  lv_label_set_text(controlText, "Arcade Control");
  lv_label_set_text(controlText1, "Tank Control");

  // lv_obj_add_action_cb(controlArcade, LV_BTN_ACTION_PR, btnSwitcher);
  // lv_obj_add_action_cb(controlTank, LV_BTN_ACTION_PR, btnSwitcher);

  lv_obj_align(controlTank, LV_ALIGN_RIGHT_MID, 0, 0);

  // lv_obj_t *switchControl = lv_sw_create(tab2, NULL);
  lv_obj_t *switchControl = lv_switch_create(tab2);
  lv_obj_align(switchControl, LV_ALIGN_CENTER, 0, 0);
}
