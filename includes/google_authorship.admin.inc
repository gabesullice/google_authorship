<?php

/**
 * Adds an administration page for this module.
 */
function google_authorship_admin() {
  $form = array();

  if (module_exists('metatag')) {
    $form['google_authorship_use_metatag'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use the Metatag module?'),
      '#default_value' => variable_get('google_authorship_use_metatag', 0),
      '#description' => t('Enable this in order to use the Metatag module to add Google Authorship metadata info to node pages and not rewrite username links. This is helpful if your theme overrides the default author and date display.'),
    );
  }

  $form['google_authorship_registration_disp'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide Google+ ID field on user registration form?'),
    '#default_value' => variable_get('google_authorship_registration_disp', 0),
    '#description' => t('Enable this if you do not want users to be able to input their Google+ ID when registering a new user account.'),
  );

  $bundles = array();

  foreach (field_info_bundles('node') as $bundle => $bundle_info) {
    $bundles[$bundle] = $bundle_info['label'];
  }

  $form['google_authorship_content_types'] = array(
    '#type' => 'select',
    '#title' => t('Display Google Authorship metadata on:'),
    '#description' => t('This determines which bundles will have Google Authorship metadata added to their markup. No selection will display Google Authorship for every bundle.'),
    '#options' => $bundles,
    '#multiple' => TRUE,
  );

  $roles = array();

  foreach (user_roles(TRUE) as $role_id => $role_name) {
    $roles[$role_id] = $role_name;
  }

  $form['google_authorship_disp_for_roles'] = array(
    '#type' => 'select',
    '#title' => t('Display Google Authorship for authors with these roles:'),
    '#description' => t('This determines which authors will have Google Authorship metadata added to their markup, based on the author\'s role. No selection will display Google Authorship for every role.'),
    '#options' => $roles,
    '#multiple' => TRUE,
  );

  return system_settings_form($form);
}