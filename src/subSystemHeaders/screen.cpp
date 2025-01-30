#include "liblvgl/lvgl.h"
#include "main.h"
#include <cstddef>
#include <cstdint>

// TODO: Style it with the School colors and make it a bit nicer to look at.
// TODO: Figuring out one wants to do the Driver control tab

// TODO: Handle Auton in seperate file
static void event_handler(lv_event_t *e) {
  lv_obj_t *obj = lv_event_get_target(e);
  lv_obj_t *tabview = lv_obj_get_parent(obj); // Get the screen
  // lv_obj_t *tab1 = lv_obj_get_child(tabview, 0);
  lv_obj_t *AutonTextName = lv_obj_get_child(
      tabview, 2); // get the AutonLabel to allow to change the text.
  // lv_obj_t *AutonTextName = lv_obj_get_child(tab1, 5);
  uint32_t id = lv_btnmatrix_get_selected_btn(
      obj); // We create a variable of the index of which button has been
            // selected, since its an array
  // printf("Button %d is %s\n", id, (lv_btnmatrix_has_btn_ctrl(obj, id,
  // LV_BTNMATRIX_CTRL_CHECKED) ? "selected" : "not selected")); // See which
  // button has been checked with the "lv_matrix_get_selected_btn()" This switch
  // case is how we are going to handle dealing with the selecting of different
  // Autons.

  switch (lv_btnmatrix_get_selected_btn(obj)) {
  case 0:
    auton = AutonType::BLUE_POS;
    printf("Blue Pos set\n");
    lv_label_set_text(AutonTextName, "Currently Selected: Blue Pos");
    break;
  case 1:
    auton = AutonType::BLUE_NEG;
    printf("Blue Neg Set\n");
    lv_label_set_text(AutonTextName, "Currently Selected: Blue Neg");
    break;
  case 2:
    auton = AutonType::RED_POS;
    printf("Red Pos set\n");
    lv_label_set_text(AutonTextName, "Currently Selected: Red Pos");
    break;
  case 3:
    auton = AutonType::RED_NEG;
    printf("Red Neg set\n");
    lv_label_set_text(AutonTextName, "Currently Selected: Red Neg");
    break;
  }
}

static void switcherControl(lv_event_t *e) {
  lv_obj_t *obj = lv_event_get_target(e);
  lv_obj_t *tabsview = lv_obj_get_parent(obj); // Get the screen
    lv_obj_t *controlLabel = lv_obj_get_child(tabsview, 1);

    switch(lv_roller_get_selected(obj)) {
        case 0:
            controlStyle = ControlType::ArcadeStyle;
            // printf("Set control type to Arcade\n");
            lv_label_set_text(controlLabel, "Control: Arcade Control");
        break;
        case 1: 
            controlStyle = ControlType::TankStyle;
            // printf("Set control type to Tank\n");
            lv_label_set_text(controlLabel, "Control: Tank Control");
        break;
        case 2:
            controlStyle = ControlType::CurvatureControl;
            // printf("Set control Type to Curvature, WIP\n");
            lv_label_set_text(controlLabel, "Control: Curvature, WIP");

    }

}

void screenInit() {

  lv_obj_t *tabview;

  tabview = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 35);

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
  
  static const char *btnm_map[] = {"Blue Pos", "Blue Neg", "\n",
                                   "Red Pos",  "Red Neg",  ""};
  lv_obj_t *switcherBtns = lv_btnmatrix_create(tab1);

  lv_btnmatrix_set_map(switcherBtns, btnm_map);

  lv_obj_add_event_cb(switcherBtns, event_handler, LV_EVENT_VALUE_CHANGED,
                      NULL);

  lv_obj_set_size(switcherBtns, LV_HOR_RES, LV_VER_RES / 2);
  lv_btnmatrix_set_btn_ctrl_all(switcherBtns, LV_BTNMATRIX_CTRL_CHECKABLE);

  lv_btnmatrix_set_one_checked(switcherBtns, true);
  lv_obj_center(switcherBtns);

  lv_label_set_text(autonName, "Test");
  lv_obj_set_y(autonName, -10);

  lv_obj_align(autonName, LV_ALIGN_BOTTOM_MID, 0, 0);

  lv_obj_t *controlList = lv_roller_create(tab2);
  lv_roller_set_options(controlList,
                        "Arcade Control\n"
                        "Tank Control\n"
                        "(WIP) Curviature Control\n",
                        LV_ROLLER_MODE_INFINITE);
  // lv_obj_align(controlList, LV_ALIGN_CENTER, 0, 0);
    lv_obj_center(controlList);
  lv_obj_add_event_cb(controlList, switcherControl, LV_EVENT_ALL, NULL);
    lv_obj_t *controlLabel = lv_label_create(tab2);
    lv_obj_align(controlLabel, LV_ALIGN_BOTTOM_MID, 0, 10);
    lv_label_set_text(controlLabel, "Control: ");

}
