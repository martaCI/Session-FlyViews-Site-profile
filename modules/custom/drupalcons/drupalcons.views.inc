<?php

/**
 * @file drupalcons.views.inc
 */

/**
 * Implements hook_views_data().
 */
function drupalcons_views_data() {
  $data = array();

  // Base table definition.
  $data['drupalcons']['table'] = array(
    'group' => t('DrupalCons'),
    'base' => array(
      'title' => t('DrupalCons'),
      'help' => t('Information about DrupalCons fetched from an external website.'),
      'query class' => 'drupalcons_query',
    ),
  );

  // ID
  $data['drupalcons']['id'] = array(
    'title' => t('ID'),
    'help' => t('Identifier of the DrupalCon.'),
    // Information for displaying the ID.
    'field' => array(
      'handler' => 'drupalcons_views_handler_field_drupalcon',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function drupalcons_views_plugins() {
  $plugins = array(
    'query' => array(
      'drupalcons_query' => array(
        'title' => t('DrupalConsAPIRequest'),
        'help' => t('Uses DrupalConsAPIRequest for querying information about DrupalCons from an external website.'),
        'handler' => 'drupalcons_views_plugin_query',
      ),
    ),
  );

  return $plugins;
}
