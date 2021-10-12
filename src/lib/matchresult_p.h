/*
    SPDX-FileCopyrightText: 2016 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: MIT
*/

#ifndef KSYNTAXHIGHLIGHTING_MATCHRESULT_P_H
#define KSYNTAXHIGHLIGHTING_MATCHRESULT_P_H

#include <QStringList>
#include <QMap>

namespace KSyntaxHighlighting
{
/**
 * Storage for match result of a Rule.
 * Heavily used internally during highlightLine, therefore completely inline.
 */
class MatchResult
{
public:
    /**
     * Match at given offset found.
     * @param offset offset of match
     */
    MatchResult(const int offset)
        : m_offset(offset)
    {
    }

    /**
     * Match at given offset found with additional skip offset.
     */
    explicit MatchResult(const int offset, const int skipOffset)
        : m_offset(offset)
        , m_skipOffset(skipOffset)
    {
    }

    /**
     * Match at given offset found with additional captures.
     * @param offset offset of match
     * @param captures captures of the match
     */
    explicit MatchResult(const int offset, const QStringList &captures, const QMap<int, QString>& attributes)
        : m_offset(offset)
        , m_captures(captures)
        , m_attributes(attributes)
    {
    }

    /**
     * Offset of the match
     * @return offset of the match
     */
    int offset() const
    {
        return m_offset;
    }

    /**
     * Skip offset of the match
     * @return skip offset of the match, no match possible until this offset is reached
     */
    int skipOffset() const
    {
        return m_skipOffset;
    }

    /**
     * Captures of the match.
     * @return captured text of this match
     */
    const QStringList &captures() const
    {
        return m_captures;
    }

    const QMap<int, QString>& attributes() const
    {
        return m_attributes;
    }

private:
    /**
     * match offset, filled in all constructors
     */
    int m_offset;

    /**
     * skip offset, optional
     */
    int m_skipOffset = 0;

    /**
     * captures, optional
     */
    QStringList m_captures;

    /**
     * Attributes for captures, optional.
     */
    QMap<int, QString> m_attributes;
};
}

#endif // KSYNTAXHIGHLIGHTING_MATCHRESULT_P_H
