### File wide comment, for reference see https://projectfluent.org
### And for a EBNF-Syntax, see https://github.com/projectfluent/fluent/blob/master/spec/fluent.ebnf


## Section comment: Simple texts
# identifier = matched word
hello-world = Hello World

# multiline text
multiline = Some text on the first line
    And more text on the next line
    One could even go further

# block text
block =
    No content on first line
    rest is like multiline


## Placeables, insert text from variables etc.
variable-placeable = We currently have { $users } users

# Term, used only in other texts, not final translation string
-name = Fluent
about = { -name } is great

# Term with parameters
-special-term = Wrapper around { $parameter }
using-wrapper = Wrapping { -special-term(parameter: "stuff") }

placeable-with-special-character = Using a {"{"}

builtin-number = Time elapsed: { NUMBER($duration, maximumFractionDigits: 0) }s.

builtin-date = Last checked: { DATETIME($lastChecked, day: "numeric", month: "long") }.


## Selectors, different options for different types of numbers
# by variable
emails =
    { $unreadEmails ->
        [one] You have one unread email.
        *[other] You have { $unreadEmails } unread emails.
    }

# by function
your-score =
    { NUMBER($score, minimumFractionDigits: 1) ->
        [0.0]   You scored zero points. What happened?
       *[other] You scored { NUMBER($score, minimumFractionDigits: 1) } points.
    }

# with keywords
your-rank = { NUMBER($pos, type: "ordinal") ->
   [1] You finished first!
   [one] You finished {$pos}st
   [two] You finished {$pos}nd
   [few] You finished {$pos}rd
  *[other] You finished {$pos}th
}

## Attributes
login-input = Predefined value
    .placeholder = email@example.com
    .aria-label = Login input value
    .title = Type your login email

# accessible via .
login-placeholder = {login-input.placeholder}
