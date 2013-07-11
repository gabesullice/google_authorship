google_authorship
=================

This module adds a field to the Drupal 7 user entity called to store a Google+
profile ID. Using that field, if it is filled, this module alters the
Submitted by line of a node's full content display to link to the Google+
profile of the appropriate author. Finally, by setting the "rel='author'"
attribute Google search bots will recognize and display an author's profile
picture in its search results.

Installation
------------

1. Add the module to /sites/all/modules (or /sites/all/modules/contrib).
2. Go to admin/modules and enable the Google Authorship module.
3. For each user for whom you would like Google to display author
   information, add their 21 digit Google+ Profile ID from their profile URL.
   You may also have user do this themselves.

   *Note*

   By default, the Google+ Profile ID field is exposed on registration and to
   users. If you would like to control who will have their pictures
   displayed, you will need to disable this in on the
   admin/config/people/accounts/fields/field_google_plus_id page.

4. Finally, ensure that the "Display Author and Date" setting is checked for all
   the content types that you would like to have Google Authorship apply its
   changes.

Important Notes
---------------

This module may not work with themes that override the submitted variable. If it
does not seem to be working, please first check that your theme does not
override it on its own.

To verify that Google can see authorship information on your nodes, you can
paste the URL of a node which this module should have overridden into Google's
Structured Data Tool at http://www.google.com/webmasters/tools/richsnippets