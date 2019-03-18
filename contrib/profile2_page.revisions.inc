<?php

function profile2_revisions_view_for_user($type, $account = NUll) {
  if ($account) {
    $uid = $account->uid;
  }
  else {
    global $user;
    $uid = $user->uid;
  }
  return profile2_revision_overview(profile2_by_uid_load($uid, $type));
}

function profile2_page_tab_revision_view($type, $account, $vid) {
  $current_profile = profile2_by_uid_load($account->uid, $type);
  $profile_revision = profile2_load($current_profile->pid, $vid);
  return profile2_view($profile_revision);
}

function profile2_page_tab_get_revision_revert($type, $account, $vid) {
  $current_profile = profile2_by_uid_load($account->uid, $type);
  $profile_revision = profile2_load($current_profile->pid, $vid);
  return drupal_get_form('profile2_revision_revert_confirm', $profile_revision);
}

function profile2_page_tab_get_revision_delete($type, $account, $vid) {
  $current_profile = profile2_by_uid_load($account->uid, $type);
  $profile_revision = profile2_load($current_profile->pid, $vid);
  return drupal_get_form('profile2_revision_delete_confirm', $profile_revision);
}
