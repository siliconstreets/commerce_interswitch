<?php
/**
 * @file
 * Default Rules.
 */

/**
 * Implements hook_default_rules_configuration().
 *
 * Creates the default rule that sets the Interswitch charge
 */
function commerce_interswitch_default_rules_configuration() {
  $rule = rules_reaction_rule();
  $rule->label = 'Set Interswitch Charge';
  $rule->active = TRUE;
  $rule->event('commerce_order_update')
       ->condition('commerce_payment_selected_payment_method', array('commerce_order:select' => 'commerce-order', 'method_id' => 'interswitch'))
       ->action('commerce_interswitch_add_interswitch_charges', array('commerce_order:select' => 'commerce-order'));

  $configs['set_interswitch_charge'] = $rule;
  return $configs;
}
