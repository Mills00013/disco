<?php

/**
 * Page callback: Disco settings
 *
 * @see disco_menu()
 */
function disco_settings_form($form, &$form_state) {
  $disco_color_values = array(
    'color' => t('Text Color'),
    'bgcolor' => t('Background Color'),
  );

  $form['disco_color'] = array(
    '#type' => 'fieldset',
    '#title' => t('Color Options'),
  );
  $form['disco_color']['disco_color_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Colors Enabled'),
    '#default_value' => variable_get('disco_color_enabled',0),
  );
  $form['disco_color']['disco_color_settings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Options'),
    '#options' => $disco_color_values,
    '#default_value' => variable_get('disco_color_settings',array(
      'color' => 0,
      'bgcolor' =>0,
    )),
    '#description' => t('Select which color options you want to apply.'),
    '#states' => array(
      'visible' => array(
        ':input[name="disco_color_enabled"]' => array(
          'checked' => TRUE
        )
      )
    ),
  );


  $disco_shadow_location = array(
    'text' => t('Text'),
    'objects' => t('Other Objects'),
  );
  $disco_shadow_values = array(
    'rancolor' => t('Random Colors'),
    'ranopacity' => t('Random Opacities'),
    'randepth' => t('Random Depth'),
  );

  $form['disco_shadows'] = array(
    '#type' => 'fieldset',
    '#title' => t('Shadow Options'),
  );
  $form['disco_shadows']['disco_shadow_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Shadows Enabled'),
    '#default_value' => variable_get('disco_shadow_enabled',0),
  );
  $form['disco_shadows']['disco_shadow_location'] = array(
    '#type' => 'checkboxes',
    '#options' => $disco_shadow_location,
    '#title' => t('Location'),
    '#default_value' => variable_get('disco_shadow_location',array(
      'text' => 0,
      'objects' =>0,
    )),
    '#description' => t('Select where you would like shadows to apply.<br />
                         If an option is not selected, a default 
                         will be applied.'),
    '#states' => array(
      'visible' => array(
        ':input[name="disco_shadow_enabled"]' => array(
          'checked' => TRUE
        )
      )
    ),
  );
  $form['disco_shadows']['disco_shadow_settings'] = array(
    '#type' => 'checkboxes',
    '#options' => $disco_shadow_values,
    '#title' => t('Options'),
    '#default_value' => variable_get('disco_shadow_settings',array(
      'rancolor' => 0,
      'ranopacity' =>0,
      'randepth' =>0,
    )),
    '#description' => t('Select which shadow options you want to apply.'),
    '#states' => array(
      'visible' => array(
        ':input[name="disco_shadow_enabled"]' => array(
          'checked' => TRUE
        )
      )
    ),
  );


  $disco_font_values = array(
    'ranfont' => t('Random Fonts'),
    'ransize' => t('Random Font Sizes'),
  );

  $form['disco_fonts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Font Options'),
  );
  $form['disco_fonts']['disco_font_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fonts Enabled'),
    '#default_value' => variable_get('disco_font_enabled',0),
  );
  $form['disco_fonts']['disco_font_settings'] = array(
    '#type' => 'checkboxes',
    '#options' => $disco_font_values,
    '#title' => t('Options'),
    '#default_value' => variable_get('disco_font_settings',array(
      'ranfont' => 0,
      'ransize' =>0,
    )),
    '#description' => t('Select which font options you want to apply.'),
    '#states' => array(
      'visible' => array(
        ':input[name="disco_font_enabled"]' => array(
          'checked' => TRUE
        )
      )
    ),
  );


  // Create a submit button and handle variable setting
  return system_settings_form($form);
}
